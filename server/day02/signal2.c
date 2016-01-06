/*************************************************************************
	> File Name: signal.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月21日 星期六 10时21分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int num){
    if(num == SIGINT){
        printf("receive the SIGINT: %d\n", num);
    }
    else if (num == SIGQUIT){
        printf("recevie the SIGQUIT: %d\n", num);
    }
}

int main()
{
    signal(SIGINT, sig_handler);
    signal(SIGQUIT, sig_handler);

    printf("enter to the while.\n");
    while(1){
        sleep(1);
    }

    exit(0);
}
