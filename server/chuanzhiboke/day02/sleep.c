/*************************************************************************
	> File Name: sleep.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月20日 星期五 20时38分59秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int num)
{
    printf("\nrecvive the signal is %d\n", num);
}

int main()
{
    int time = 20;

    signal(SIGINT, sig_handler);
    printf("enter to the sleep.\n");
    //sleep(time);
    do{
        time = sleep(time);
    }while(time > 0);

    printf("sleep is over, main over.\n");

    exit(0);
}
