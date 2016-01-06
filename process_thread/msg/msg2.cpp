/*************************************************************************
	> File Name: msg1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月17日 星期四 20时25分44秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
using namespace std;

struct msg_buf {
    long mtype;       /* message type, must be > 0 */
    char mtext[100];    /* message data */
};

/*
生成一个key值,ftok（首先要先创建一个文件myMsgFile）
创建消息队列,msgget
生成消息结构体对象并填充消息类型-一般是PID和数据内容
将消息写到消息队列
睡眠3秒
从消息队列里面读出来
*/

int main()
{
    key_t key;
    key = ftok("./myMsgFile", 'k');
   
    int msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0666);
    if(msgid == -1){
        if(errno == EEXIST){
            key = ftok("./myMsgFile", 'k');
            msgid = msgget(key, IPC_CREAT | 0666);
        }
        else{
            cout << "msgget error..." << endl;
            exit(-1);
        }
    }

    struct msg_buf msgbuf;
    int msg_type = getpid();
    msgbuf.mtype = msg_type;
    strcpy(msgbuf.mtext, "message1 data");
    
    int ret = msgsnd(msgid, &msgbuf, strlen(msgbuf.mtext), IPC_NOWAIT);
    if(ret == -1){
        cout << "msgsnd error..." << endl;
        exit(-1);
    }

    memset(&msgbuf, 0, sizeof(msgbuf));
    msgbuf.mtype = 111;
    strcpy(msgbuf.mtext, "message2 data");
    ret = msgsnd(msgid, &msgbuf, strlen(msgbuf.mtext), IPC_NOWAIT);
    if(ret == -1){
        cout << "msgsnd error..." << endl;
        exit(-1);
    }


    sleep(5);
    pid_t pid = fork();
    if(pid < 0){
        cout << "fork error..." << endl;
        exit(-1);
    }
    else if (pid == 0){
        memset(&msgbuf, 0, sizeof(msgbuf));
        ret = msgrcv(msgid, &msgbuf, sizeof(msgbuf), 111, IPC_NOWAIT); //获得第二条消息
        if(ret == -1){
            cout << "msgrcv error..." << endl;
            exit(-1);
        }
        cout << "child process receive the data is: " << msgbuf.mtext << endl;
        cout << "child exit..." << endl;
        exit(0);
    }
    
    int child_status;
    wait(&child_status);
    
    cout << "parent exit..." << endl;
    exit(0);
}
