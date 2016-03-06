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

#define FIFO "/root/fifo.serv"
#define BUFF_SIZE 1024

void server(int readfd, int writefd);
void client(int readfd, int writefd);

int main(int argc, char* argv[])
{
    char buff[BUFF_SIZE], fifoname[BUFF_SIZE];

    int readfd, writefd, dummyfd,  fd;
    pid_t pid;
    int n = 0;
    char* ptr;

    int ret = mkfifo(FIFO, O_CREAT|O_EXCL);
    if((ret < 0) && errno != EEXIST){
        printf("mkfifo FIFO1 error\n");
        exit(-1);
    }

    readfd = open(FIFO, O_RDONLY);
    dummyfd = open(FIFO, O_WRONLY);

    while((n = read(readfd, buff, BUFF_SIZE)) > 0){
        write(STDOUT_FILENO, buff, n);
       //空格之前的是pid，空格之后的是文件的路径名字
        if(buff[n-1] == '\n'){
            n--;
        }

        buff[n] = 0;

        if((ptr = strchr(buff, ' ')) == NULL){
            printf("错误，客户输入错误...\n");
            continue;
        }

        *ptr++ = 0;
        pid = atol(buff);

        snprintf(fifoname, sizeof(fifoname), "/root/fifo.%ld", (long)pid);

        if((writefd = open(fifoname, O_WRONLY, 0)) < 0){
            printf("open error\n");
            continue;
        }

        if((fd = open(ptr, O_RDONLY)) < 0){
            close(writefd);
        }
        else{
            while((n = read(fd, buff, BUFF_SIZE)) > 0){
                write(writefd, buff, n);
            }
            close(fd);
            close(writefd);
        }
    }
    
    printf("server over..\n");
    close(readfd);
    close(dummyfd);
    unlink(FIFO);

    exit(0);
}

