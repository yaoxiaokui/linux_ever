/*************************************************************************
	> File Name: signal_kill.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月15日 星期二 09时37分29秒
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void sig_handler(int sig_num)
{
    if(sig_num == SIGUSR1)
        printf("%d received SIGUSR1\n", getpid());
    else if(sig_num == SIGUSR2)
        printf("%d received SIGUSR2\n", getpid());
    else
        printf("%d other condition\n", getpid());

}


int main()
{

    if(signal(SIGUSR1, sig_handler) == SIG_ERR){
        printf("signal SIGUSR1 error...\n");
        return -1;
    }
    if(signal(SIGUSR2, sig_handler) == SIG_ERR){
        printf("signal SIGUSR1 error...\n");
        return -1;
    }
    
    for( ; ; )
        pause();

    return 0;
}
