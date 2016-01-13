/*************************************************************************
	> File Name: fork2.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月18日 星期三 20时45分25秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <signal.h>
void main()
{

        pid_t pid;
        signal(SIGCHLD, SIG_IGN);
        int fd;
        fd = open("test.txt", O_WRONLY);
        if (fd == -1)
    {
                perror("open err");
                exit(0);
            
    }
        
        pid = fork();
        if (pid == -1)
    {
                perror("fork err");
                return -1;
            
    }

        if (pid == 0)
    {
                printf("this is child pid:%d ppid:%d \n", getpid(), getppid());
                write(fd, "child", 5);
                //sleep(20);20
        //
    }

        if (pid > 0)
    {
                printf("this is parent pid:%d ppid:%d \n", getpid(), getppid());
                write(fd, "parent", 5);
                //sleep(20);
        //
    }

        printf("fork() after\n");
        sleep(1);
        close(fd);
        return 0;

}


