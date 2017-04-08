/*************************************************************************
	> File Name: execl.c 
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Jun 2016 10:11:10 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>


int main()
{
    printf("进程pid = %d\n", getpid());

    execl("/bin/ls", "ls", "-lh", NULL);

    sleep(10);//为了用ps查看进程的PID
    printf("进程退出\n");

    return 0;
}
