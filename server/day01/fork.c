#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void TestFun(int loopnum)
{
	printf("loopnum: %d\n", loopnum);
}

int main()
{
	int procnum = 10;
	int loopnum = 100;
    int fd;

	int i = 0;
	int j = 0;
	printf("Please input your procnum: ");
	scanf("%d", &procnum);
	printf("Please input your loopnum: ");
	scanf("%d", &loopnum);
	
	pid_t pid;
	for (i = 0; i < procnum; ++i){
		pid = fork();
		if (pid == 0){
			for (j = 0; j < loopnum; ++j){
				TestFun(j);
			}
			exit(0);
		}
	}

	exit(0);	
}
