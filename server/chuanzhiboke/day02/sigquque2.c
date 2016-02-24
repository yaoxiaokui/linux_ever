/*************************************************************************
	> File Name: sigquque.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月21日 星期六 14时33分25秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

//用新的回到函数接受数据。。。。  
void myHandle_forsigaction(int signum, siginfo_t *s_t, void *p)
{
	printf("parent recv a sig=%d data=%d data=%d\n", signum, s_t->si_value.sival_int, s_t->si_int);
}


int main(int argc, char *argv[])
{
	pid_t 	pid;
	int ret = 0;
	
	struct sigaction act;
	act.sa_sigaction = myHandle_forsigaction;
	sigemptyset(&act.sa_mask);
	
	//如果父进程的回调函数， 准备接受额外数据
	act.sa_flags = SA_SIGINFO;

	if (sigaction(SIGINT, &act, NULL) < 0)
	    perror("sigaction error\n");

	pid = fork();
	
	if (pid == -1)
	{
		printf("fork err...\n");
		return 0;
	}
	
	if (pid == 0)
	{
		int i = 0;
		
		/*
         union sigval {
             int   sival_int;
             void *sival_ptr;
         }; */
         
	   union sigval  mysigval;
	   //mysigval.sival_ptr = (void *)&t;
	   mysigval.sival_int = 222;	
	
		//kill(getppid(), SIGINT);
		//带额外数据
		for (i=0; i<10; i++)
		{
			ret  = sigqueue(getppid(), SIGINT, mysigval);
			if (ret != 0)
			{
				printf("sigqueue .....\n");
				exit(0);
			}
			else
			{
				printf("child send the SIGINT signal by the funtion sigqueue...\n");
				sleep(1);
			}
		}
        exit(10);
	}
	else if (pid > 0)
	{
        int time = 20;
        while(time){
            time = sleep(time);
        }
	}

    exit(0);
}