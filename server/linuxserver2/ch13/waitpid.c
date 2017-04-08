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
#include <signal.h>

//父进程创建2个子进程
const int child_num = 2;


//下面是SIGCHLD信号的信号处理函数
void handle_child(int sig_num)
{
    int status;
    pid_t pid;


    printf("sig_num = %d\n", sig_num);
    while(1){
        pid = waitpid(-1, &status, WNOHANG);
        if(pid > 0){
            printf("wait child pid = %d, child exit code  = %d\n", pid, WEXITSTATUS(status));
            break;
        }
    }

}

int main()
{
    int child_pids[child_num];
    int i = 0;

    signal(SIGCHLD, handle_child);

    for(i = 0; i < child_num; ++i){
        child_pids[i] = fork();
        if(child_pids[i] == 0){
            printf("子进程%d, pid = %d\n", i+1, getpid());
            sleep(1);//睡眠一下，为了用ps查看它们的pid
            exit(getpid());//子进程把自己的PID作为退出码返回
        }
        else if(child_pids[i] > 0){
            printf("父进程pid = %d, 子进程pid = %d\n", getpid(), child_pids[i]);
        }
        else{
            printf("fork error\n");
            exit(0);
        }
    }

    //sleep(5);//如果使用sleep的话，只能接收到一次SIGCHLD信号，因为sleep是可中断睡眠
    //下面的睡眠方法，可以避免信号的中断
    int time = 2;
    do{
        time = sleep(time);//中断完之后继续睡眠剩下的时间
    }while(time > 0);

    return 0;
}
