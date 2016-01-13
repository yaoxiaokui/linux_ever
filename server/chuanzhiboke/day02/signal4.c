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
        sigset_t new_set;
        sigaddset(&new_set, SIGINT);

        sigprocmask(SIG_UNBLOCK, &new_set, NULL);
    }
}

void print_sig_set(sigset_t * set)
{
    int i;

    for (i = 1; i <= 64; ++i){
        if (sigismember(set, i)){
            putchar('1');
        }
        else{
            putchar('0');
        }
    }
    printf("\n");
}

int main()
{
    
    sigset_t block_set;
    sigset_t pending_set;

    sigemptyset(&block_set);
    sigaddset(&block_set, SIGINT);

    signal(SIGINT, sig_handler);
    signal(SIGQUIT, sig_handler);

    sigprocmask(SIG_BLOCK, &block_set, NULL);
    
    int time = 10;
    while(time){
        sigpending(&pending_set);
        print_sig_set(&pending_set);
        sleep(1);
        time--;
    }
    printf("first sleep is over.\n");
    
    sigprocmask(SIG_UNBLOCK, &block_set, NULL);
    while(1){
        sigpending(&pending_set);
        print_sig_set(&pending_set);
        sleep(1);
    }

    exit(0);
}
