/*************************************************************************
	> File Name: mainpipe.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月04日 星期五 16时13分19秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO1 "/root/fifo.1"
#define FIFO2 "/root/fifo.2"

void client(int readfd, int writefd);

int main(int argc, char* argv[])
{
    int readfd, writefd;
    pid_t pid;
    
    readfd = open(FIFO1, O_RDONLY);
    writefd = open(FIFO2, O_WRONLY);

    client(readfd, writefd);

    close(readfd);
    close(writefd);
    unlink(FIFO1);
    unlink(FIFO2);

    exit(0);
}


void client(int readfd, int writefd)
{
    char buff[1024];
    printf("I am client, please intput the file name: ");

    fgets(buff, 1024, stdin);

    //发送到writefd中
    int len = strlen(buff);

    if(buff[len-1] == '\n')
        len--;

    write(writefd, buff, len);
    
    int size = 0;
    printf("client receive the data is: \n");
    while((size = read(readfd, buff, 1024)) > 0){
        write(STDOUT_FILENO, buff, size);
    }
}

