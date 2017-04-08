/*************************************************************************
	> File Name: cloneTest1.c
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Nov 2016 12:36:36 PM CST
 ************************************************************************/

#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sched.h>
#include <signal.h>
#include <unistd.h>

//定义一个给clone用的栈，栈大小为1M
#define STACK_SIZE (1024 * 1024)

static char container_stack[STACK_SIZE];

char * const container_args[] = {
    "/bin/bash",
    NULL
};


int container_main(void * arg)
{
    printf("Container [%5d] - inside the container!\n", getpid());
    sethostname("container", 10);    
    execv(container_args[0], container_args);
    printf("Something is wrong!\n");

    return 1;
}


int main()
{
    printf("Parent [%5d] - start a container!\n", getpid());

    int container_pid = clone(container_main, container_stack + STACK_SIZE, CLONE_NEWUTS | CLONE_NEWPID | SIGCHLD, NULL);

    waitpid(container_pid, NULL, 0);
    printf("Parent - container stopped!\n");

    return 0;
}
