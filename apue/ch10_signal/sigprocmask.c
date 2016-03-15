/*************************************************************************
	> File Name: sigprocmask.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月15日 星期二 20时17分01秒
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

void sig_handler(int sig_num)
{
    printf("receive the signal: %d\n", sig_num);
    sigset_t sa;

    int errno_save = errno;

    if(sigprocmask(0, NULL, &sa) != 0){
        printf("sigprocmask error\n");
        return;
    }

    if(sigismember(&sa, SIGINT)){//因为此时产生了SIGINT信号，并正在处理该信号。此时该信号已经被阻塞，当处理完该信号之后，又恢复阻塞。
        printf("SIGINT\n");
    }

    if(sigismember(&sa, SIGQUIT)){
        printf("SIGQUIT\n");
    }


    errno = errno_save;
}


int main()
{
    signal(SIGINT, sig_handler);
    signal(SIGQUIT, sig_handler);


    for(; ;)
        pause();

    return 0;
}
