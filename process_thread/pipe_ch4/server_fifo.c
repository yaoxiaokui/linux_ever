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

void server(int readfd, int writefd);

int main(int argc, char* argv[])
{
    int readfd, writefd;
    pid_t pid;
    
    int ret = mkfifo(FIFO1, O_CREAT|O_EXCL);
    if((ret < 0) && errno != EEXIST){
        printf("mkfifo FIFO1 error\n");
        exit(-1);
    }

    ret = mkfifo(FIFO2, O_CREAT|O_EXCL);
    if((ret < 0) && errno != EEXIST){
        printf("mkfifo FIFO2 error\n");
        unlink(FIFO1);
        exit(-1);
    }
//子进程从FIFO1读，从FIFO2写
///父进程从FIFO2读，向FIFO1写

    writefd = open(FIFO1, O_WRONLY);
    readfd = open(FIFO2, O_RDONLY);
    server(readfd, writefd);
        
    exit(0);
}


void server(int readfd, int writefd)
{

    //printf("I am server...\n");
    char buff[1024];

    int n = read(readfd, buff, 1024);
    buff[n] = 0;

    int fd = open(buff, O_RDONLY);
    if(fd < 0){
        printf("open error\n");
        exit(-1);
    }

    while((n = read(fd, buff, 1024)) > 0){
        write(writefd, buff, n);
    }

    close(fd);
}
