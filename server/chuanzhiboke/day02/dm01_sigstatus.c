
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <signal.h>


//演示信号从产生到抵达的整个过程
//信号的阻塞和解除阻塞综合实验
//设置信号阻塞和非阻塞，设置ctl+q来解除信号阻塞

#define ERR_EXIT(m) \
	do \
	{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)

void handler(int sig);

void handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("recv a sig=%d\n", sig);
		printf("\n\n\n");
		//fflush(stdout);
	}
	else if (sig == SIGQUIT)
	{
		sigset_t uset;
		sigemptyset(&uset);
		sigaddset(&uset, SIGINT);
		//ctr + \ 用来接触  SIGINT 信号
		//解除阻塞
		sigprocmask(SIG_UNBLOCK, &uset, NULL);
		
		//signal(SIGINT, SIG_DFL) ;
	}
}

void printsigset(sigset_t *set)
{
	int i;
	for (i=1; i<NSIG; ++i)
	{
		if (sigismember(set, i))
			putchar('1');
		else
			putchar('0');
	}
	printf("\n");
}

//测试显示 信号未达状态 关键字
int main01(int argc, char *argv[])
{
	sigset_t pset;
	
	//sigset_t bset;
	//sigemptyset(&bset);
	//sigaddset(&bset, SIGINT);
	//按照信号 信号因为没有阻塞直接抵达
	
	
	/*
	if (signal(SIGINT, handler) == SIG_ERR)
		ERR_EXIT("signal error");
	*/
		/*
	if (signal(SIGQUIT, handler) == SIG_ERR)
		ERR_EXIT("signal error");
		sigprocmask(SIG_BLOCK, &bset, NULL);
	*/
	
	for (;;)
	{
		//获取信号未决  sigset_t字
		sigpending(&pset); 
		//打印信号未决  sigset_t字
		//信号没有被阻塞，信号没有未决，所以没有东西
		printsigset(&pset);
		sleep(2);
	}
	return 0;
}

//测试显示 信号未达状态 关键字 + 注册SIGINT信号
int main02(int argc, char *argv[])
{
	sigset_t pset;
	
	//sigset_t bset;
	//sigemptyset(&bset);
	//sigaddset(&bset, SIGINT);
	//按照信号 信号因为没有阻塞直接抵达
	
	if (signal(SIGINT, handler) == SIG_ERR)
		ERR_EXIT("signal error");
		/*
	if (signal(SIGQUIT, handler) == SIG_ERR)
		ERR_EXIT("signal error");
		sigprocmask(SIG_BLOCK, &bset, NULL);
	*/
	
	for (;;)
	{
		//获取信号未决  sigset_t字
		sigpending(&pset); 
		//打印信号未决  sigset_t字
		//信号没有被阻塞，信号没有未决，所以没有东西
		printsigset(&pset);
		sleep(2);
	}
	return 0;
}

//3 连续的按ctrl+c键盘，虽然发送了多个SIGINT信号，但是因为信号是不稳定的，只保留了一个。
//不支持排队
int main(int argc, char *argv[])
{
	sigset_t pset; //用来打印的信号集
	sigset_t bset; //用来设置阻塞的信号集
	
	sigemptyset(&bset);
	sigaddset(&bset, SIGINT);
	
	if (signal(SIGINT, handler) == SIG_ERR)
		ERR_EXIT("signal error");
		
	if (signal(SIGQUIT, handler ) == SIG_ERR)
		ERR_EXIT("signal error");

	//读取或更改进程的信号屏蔽字 这里用来阻塞ctrl+c信号
	//ctrl+c信号被设置成阻塞，即使用户按下ctl+c键盘，也不会抵达
	sigprocmask(SIG_BLOCK, &bset, NULL);
	
	for (;;)
	{
		//获取未决 字信息
		sigpending(&pset);
		
		//打印信号未决  sigset_t字
		printsigset(&pset);
		sleep(1);
	}
	return 0;
}



