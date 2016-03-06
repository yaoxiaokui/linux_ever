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

#define SERV_FIFO "/root/fifo.serv"
#define BUFF_SIZE 1024

int main(int argc, char* argv[])
{
    char buff[BUFF_SIZE], fifoname[BUFF_SIZE];

    int readfd, writefd, fd;
    pid_t pid;
    int n = 0;
    char* ptr;

    pid = getpid();
    snprintf(fifoname, sizeof(fifoname), "/root/fifo.%ld", (long)pid);

    int ret = mkfifo(fifoname, O_CREAT|O_EXCL);
    if((ret < 0) && errno != EEXIST){
        printf("mkfifo FIFO1 error\n");
        exit(-1);
    }

    snprintf(buff, sizeof(buff), "%ld", (long)pid);
    int len = strlen(buff);
    ptr = buff + len;

    *(ptr++) = ' ';
    printf("input the file name: ");
    fgets(ptr, BUFF_SIZE-len, stdin);//input the file name 
    len = strlen(buff);
    write(STDOUT_FILENO, buff, len);

    writefd = open(SERV_FIFO, O_WRONLY);
    write(writefd, buff, len);

    readfd = open(fifoname, O_RDONLY);

    while((n = read(readfd, buff, BUFF_SIZE)) > 0){
        write(STDOUT_FILENO, buff, n);
    }
    
    close(readfd);
    unlink(fifoname);

    exit(0);
}

