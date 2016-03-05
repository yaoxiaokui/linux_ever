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
void client(int readfd, int writefd);

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

    pid = fork();
    if(pid < 0){
        printf("fork error\n");
        exit(-1);
    }
    else if(pid == 0){//子进程
        readfd = open(FIFO1, O_RDONLY);
        writefd = open(FIFO2, O_WRONLY);
        server(readfd, writefd);
    }
    else if(pid > 0){//父进程
        writefd = open(FIFO1, O_WRONLY);
        readfd = open(FIFO2, O_RDONLY);
        client(readfd, writefd);
        
    }

    waitpid(pid, NULL, 0);
    
    close(readfd);
    close(writefd);
    unlink(FIFO1);
    unlink(FIFO2);


    exit(0);
}


/*
    父进程是客户端，从stdin输入文件名，写入到管道1，pipefd1[1];
    子进程是服务器，从管道1,pipefd1[0]读出文件名字。然后将文件的内容写到管道2，pipefd2[1]
    父进程再从管道2读取文件的内容,pipefd2[0]
*/

//父进程
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


/*
    父进程是客户端，从stdin输入文件名，写入到管道1，pipefd1[1];
    子进程是服务器，从管道1,pipefd1[0]读出文件名字。然后将文件的内容写到管道2，pipefd2[1]
    父进程再从管道2读取文件的内容,pipefd2[0]
*/
//子进程
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
