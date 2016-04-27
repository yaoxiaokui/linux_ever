/*************************************************************************
	> File Name: fifoserver.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月27日 星期三 22时28分21秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>


#define MAXLINE 1024
#define SERV_FIFO "/tmp/fifo.serv"

int main(int argc, char * argv[])
{
    int readfifo, writefifo, dummyfd, fd;
    char * ptr, buffer[MAXLINE+1], fifoname[MAXLINE+1];
    pid_t pid;

    ssize_t n;

    //创建服务器的fifo
    if((mkfifo(SERV_FIFO, S_IRWXU)) > 0 && (errno != EEXIST)){
        printf("mkfifo errno\n");
        return -1;
    }
    //打开fifo来读
    readfifo = open(SERV_FIFO, O_RDONLY, 0);
    dummyfd = open(SERV_FIFO, O_WRONLY, 0);

    //循环等待客户端连接
    while((n = read(readfifo, buffer, MAXLINE)) > 0){
        if(buffer[n-1] == '\n')
            n--;
        buffer[n] = '\0';

        //如果客户端输入的数据不对，那么直接忽略该请求
        if((ptr = strchr(buffer, ' ')) == NULL)
            continue;
        //如果客户端输入的数据正确:PID, 路径名
        *ptr++ = '\0';
        pid = atol(buffer);
        snprintf(fifoname, sizeof(fifoname), "/tmp/fifo.%ld", (long)pid);

        //fifoname里面存放的是客户端fifo的名字
        if((writefifo = open(fifoname, O_WRONLY, 0)) < 0)
            continue;//如果打开错误则忽略该请求

        //如果打开成功，则打开文件，并将文件的内容，写入到writefifo中
        if((fd = open(ptr, O_RDONLY)) < 0){//打开文件失败
            memset(buffer, 0, MAXLINE);
            snprintf(buffer, sizeof(buffer), "can't open the file.");
            write(writefifo, buffer, MAXLINE);
            close(writefifo);
        }
        else{//成功打开文件
            while((n = read(fd, buffer, MAXLINE)) > 0)
            write(writefifo, buffer, n);
            close(fd);
            close(writefifo);
        }

    }

    return 0;
}
