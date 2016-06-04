/*************************************************************************
	> File Name: msg.c
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jun 2016 11:20:35 AM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>

//设置消息的格式
struct msgbuf{
    long mtype;
    char mtext[1024];
};


//打印消息队列的信息
void msg_print(int msqid)
{
    struct msqid_ds info;
    //获得msqid标识的消息队列的信息
    int ret = msgctl(msqid, IPC_STAT, &info);
    if(ret < 0){
        printf("msgctl error\n");
        return;
    }

    printf("------------------------------------\n");
    printf("队列中的字节总数: %ld\n", info.__msg_cbytes);
    printf("队列中的消息的数量: %ld\n", info.msg_qnum);
    printf("队列中的允许的最大字节数: %ld\n", info.msg_qbytes);
    printf("------------------------------------\n");
}


//主函数
int main(int argc, char * argv[])
{

    //创建消息队列，如果0x1234消息队列存在则打开消息队列
    int msqid = msgget(0x1234, 0666 | IPC_CREAT | IPC_EXCL);
    if(msqid < 0){
        if(errno == EEXIST)
            msqid = msgget(0x1234, 0666);
        else{
            printf("msgget error\n");
            return -1;
        }
    }

    printf("写入消息之前打印消息队列的信息.\n");
    msg_print(msqid);

    //向消息队列中写入数据
    struct msgbuf msg_buff;
    memset(&msg_buff, 0, sizeof(msg_buff));
    msg_buff.mtype = 1;
    strcpy(msg_buff.mtext, "message 1.");
    //向消息队列中写入消息1
    msgsnd(msqid, &msg_buff, strlen(msg_buff.mtext), IPC_NOWAIT);


    memset(&msg_buff, 0, sizeof(msg_buff));
    msg_buff.mtype = 2;
    strcpy(msg_buff.mtext, "message 2.");
    //向消息队列中写入消息2
    msgsnd(msqid, &msg_buff, strlen(msg_buff.mtext), IPC_NOWAIT);

    printf("写入消息之后打印消息队列的信息.\n");
    msg_print(msqid);

    /*
    //从消息队列中读取消息1
    struct msgbuf msg_recv_buff;
    memset(&msg_recv_buff, 0, sizeof(msg_recv_buff));

    msgrcv(msqid, &msg_recv_buff, 1024, 1, IPC_NOWAIT);
    printf("消息1: %s\n", msg_recv_buff.mtext);


    //从消息队列中读取消息2
    memset(&msg_recv_buff, 0, sizeof(msg_recv_buff));

    msgrcv(msqid, &msg_recv_buff, 1024, 2, IPC_NOWAIT);
    printf("消息2: %s\n", msg_recv_buff.mtext);
    */

    //删除消息队列
    //msgctl(msqid, IPC_RMID, NULL);

    return 0;
}
