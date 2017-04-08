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
#include <sys/wait.h>
#include <semaphore.h>
//父进程创建1个子进程
const int child_num = 1;


int main()
{
    int child_pids[child_num];
    int i = 0;


    for(i = 0; i < child_num; ++i){
        child_pids[i] = fork();
        if(child_pids[i] == 0){

            for(int i = 0; i < 5; ++i){
                sleep(1);//睡眠一下，为了用ps查看它们的pid
                printf("子进程pid = %d\n", getpid());
            }

            exit(getpid());//子进程把自己的PID作为退出码返回
        }
        else if(child_pids[i] > 0){

            for(int i = 0; i < 5; ++i){
                sleep(1);
                printf("父进程pid = %d\n", getpid());
            }
        }
        else{
            printf("fork error\n");
            exit(0);
        }
    }

    sleep(1);

    int status;
    pid_t pid;

    while(1){
        pid = wait(&status);
        if(pid < 0)
            break;
        printf("wait child pid = %d, child exit code  = %d\n", pid, WEXITSTATUS(status));
        //WEXITSTATUS(status)的返回值是子进程退出码的低8位
        
    }

    return 0;
}
