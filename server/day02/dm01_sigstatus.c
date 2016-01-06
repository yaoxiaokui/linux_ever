
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


//��ʾ�źŴӲ������ִ����������
//�źŵ������ͽ�������ۺ�ʵ��
//�����ź������ͷ�����������ctl+q������ź�����

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
		//ctr + \ �����Ӵ�  SIGINT �ź�
		//�������
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

//������ʾ �ź�δ��״̬ �ؼ���
int main01(int argc, char *argv[])
{
	sigset_t pset;
	
	//sigset_t bset;
	//sigemptyset(&bset);
	//sigaddset(&bset, SIGINT);
	//�����ź� �ź���Ϊû������ֱ�ӵִ�
	
	
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
		//��ȡ�ź�δ��  sigset_t��
		sigpending(&pset); 
		//��ӡ�ź�δ��  sigset_t��
		//�ź�û�б��������ź�û��δ��������û�ж���
		printsigset(&pset);
		sleep(2);
	}
	return 0;
}

//������ʾ �ź�δ��״̬ �ؼ��� + ע��SIGINT�ź�
int main02(int argc, char *argv[])
{
	sigset_t pset;
	
	//sigset_t bset;
	//sigemptyset(&bset);
	//sigaddset(&bset, SIGINT);
	//�����ź� �ź���Ϊû������ֱ�ӵִ�
	
	if (signal(SIGINT, handler) == SIG_ERR)
		ERR_EXIT("signal error");
		/*
	if (signal(SIGQUIT, handler) == SIG_ERR)
		ERR_EXIT("signal error");
		sigprocmask(SIG_BLOCK, &bset, NULL);
	*/
	
	for (;;)
	{
		//��ȡ�ź�δ��  sigset_t��
		sigpending(&pset); 
		//��ӡ�ź�δ��  sigset_t��
		//�ź�û�б��������ź�û��δ��������û�ж���
		printsigset(&pset);
		sleep(2);
	}
	return 0;
}

//3 �����İ�ctrl+c���̣���Ȼ�����˶��SIGINT�źţ�������Ϊ�ź��ǲ��ȶ��ģ�ֻ������һ����
//��֧���Ŷ�
int main(int argc, char *argv[])
{
	sigset_t pset; //������ӡ���źż�
	sigset_t bset; //���������������źż�
	
	sigemptyset(&bset);
	sigaddset(&bset, SIGINT);
	
	if (signal(SIGINT, handler) == SIG_ERR)
		ERR_EXIT("signal error");
		
	if (signal(SIGQUIT, handler ) == SIG_ERR)
		ERR_EXIT("signal error");

	//��ȡ����Ľ��̵��ź������� ������������ctrl+c�ź�
	//ctrl+c�źű����ó���������ʹ�û�����ctl+c���̣�Ҳ����ִ�
	sigprocmask(SIG_BLOCK, &bset, NULL);
	
	for (;;)
	{
		//��ȡδ�� ����Ϣ
		sigpending(&pset);
		
		//��ӡ�ź�δ��  sigset_t��
		printsigset(&pset);
		sleep(1);
	}
	return 0;
}



