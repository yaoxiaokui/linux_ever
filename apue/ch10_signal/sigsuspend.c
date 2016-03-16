/*************************************************************************
	> File Name: sigsuspend.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月16日 星期三 20时07分29秒
 ************************************************************************/

#include <stdio.h>
#include <signal.h>

void sig_handler(int sig_num)
{
    if(sig_num == SIGINT){
        printf("Receive the signal is SIGINT\n");
    }
    if(sig_num == SIGUSR1){
        printf("Receive the sigsnal is SIGUSR1\n");
    }
}

int main()
{
    sigset_t wait_set, old_set, new_set;

    //阻塞SIGINT, SIGINT添加到new_set中
    //SIGUSR1添加到wait_set中
    signal(SIGINT, sig_handler);

    sigemptyset(&wait_set);
    sigemptyset(&old_set);
    sigemptyset(&new_set);

    sigaddset(&new_set, SIGINT);
    sigaddset(&wait_set, SIGUSR1);
    
    int ret = sigprocmask(SIG_BLOCK, &new_set, &old_set);//阻塞SIGINT信号
    if(ret < 0){
        printf("sigprocmask error\n");
        return -1;
    }

    //进入临界区
    printf("进入临界区了....\n");

    ret = sigsuspend(&wait_set);//挂起该进程，直到捕获到信号SIGUSR1
    if(ret < 0){
        printf("sigsuspend error\n");
        return -1;
    }

    printf("退出了函数sigsuspend\n");

    //恢复以前的屏蔽信号状态字
    ret = sigprocmask(SIG_SETMASK, &old_set, NULL);
    if(ret < 0){
        printf("sigprocmask error\n");
        return -1;
    }
    
    printf("进程退出..\n");

    return 0;
}
