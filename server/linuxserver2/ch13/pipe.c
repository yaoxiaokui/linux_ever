/*************************************************************************
	> File Name: fork.c
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Jun 2016 10:11:10 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int child_pid;
    int pipefds[2];
    int i;

    int ret = pipe(pipefds);
    if(ret != 0){
        printf("pipe error\n");
        return -1;
    }

    //让父进程向管道fd[1]写入数据
    //让子进程从管道fd[0]读出数据

    child_pid = fork();
    if(child_pid == 0){

        //close(pipefds[1]);//子进程关闭写端
        printf("子进程pid = %d\n", getpid());
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));

        //从管道中读出数据
        for(i = 0; i < 10; ++i){
            read(pipefds[0], buffer, sizeof(buffer));
            printf("子进程读出: %s\n", buffer);

            memset(buffer, 0, sizeof(buffer));
        }
    }
    else if(child_pid > 0){
        //close(pipefds[0]);//父进程关闭读端
        printf("父进程pid = %d, 子进程pid = %d\n", getpid(), child_pid);

        char * str = "Hello pipe!";

        //向管道写入数据
        for(i = 0; i < 10; ++i){
            write(pipefds[1], str, strlen(str));
            sleep(1);
        }
    }
    else{
        printf("fork error\n");
        exit(0);
    }

    int status;
    wait(&status);

    return 0;
}
