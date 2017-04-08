/*************************************************************************
	> File Name: pipe_test1.c
	> Author: 
	> Mail: 
	> Created Time: Fri 27 May 2016 03:31:31 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


void childRead(int readfd)
{
    char buffer[1024];
    memset(buffer, 0, 1024);

    read(readfd, buffer, 1024);

    printf("Child read: %s", buffer);

    close(readfd);
}

void parentWrite(int writefd)
{
    printf("Parent write: ");
    char buffer[1024];
    memset(buffer, 0, 1024);
    fgets(buffer, 1024, stdin);

    write(writefd, buffer, strlen(buffer));

    close(writefd);
}

int main()
{
    int pipefds[2];

    int ret = pipe(pipefds);
    if(ret < 0){
        printf("pipe error\n");
        return -1;
    }

    //1写，0读
    pid_t pid = fork();
    if(pid == 0){//子进程

        close(pipefds[1]);
        childRead(pipefds[0]);
    }
    else if(pid > 0){//父进程

        close(pipefds[0]);
        parentWrite(pipefds[1]);
    }
    else{
        printf("fork error\n");
        return -1;
    }

    int status;
    waitpid(pid, &status, 0);

    return 0;
}
