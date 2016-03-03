/*************************************************************************
	> File Name: msgget.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月03日 星期四 22时05分21秒
 ************************************************************************/

//用于测试msgget每次返回的数值大小
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(int argc, char*argv[])
{
    int i, msgid;
    struct msqid_ds buff;


    for(i = 0; i < 10; i++){
        msgid = msgget(IPC_PRIVATE, IPC_CREAT);
        printf("msgid = %d, ", msgid);
        msgctl(msgid, IPC_RMID, NULL);
        msgctl(msgid, IPC_STAT, &buff);
        printf("seq = %d\n", buff.msg_perm.__seq);
    }

    return 0;
}

