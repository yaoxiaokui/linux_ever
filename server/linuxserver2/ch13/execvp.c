/*************************************************************************
	> File Name: execl.c 
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Jun 2016 10:11:10 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>


int main()
{

    pid_t child_pids;
    char *arg[] = {"ls", "-lh", NULL};

    child_pids = fork();
    if(child_pids == 0){
        printf("子进程pid = %d\n", getpid());
        printf("替换为ls的镜像，参数arg为\"-lh\"\n");
        execvp("ls", arg);
    }
    else if(child_pids > 0){
        printf("父进程pid = %d, 子进程pid = %d\n", getpid(), child_pids);
    }
    else{
        printf("fork error\n");
        exit(0);
    }

    sleep(10);//为了用ps查看进程的PID


    return 0;
}
