/*************************************************************************
	> File Name: alarm.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月20日 星期五 21时12分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int num)
{
    printf("receive the signal %d.\n", num);
    alarm(2);
}

int main()
{
    signal(SIGALRM, sig_handler);

    alarm(2);

    while(1){
        pause();
        printf("pause is over.\n");
    }

    exit(0);
}
