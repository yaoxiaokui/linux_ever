/*************************************************************************
	> File Name: mainpipe.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月20日 星期三 22时25分15秒
 ************************************************************************/


/*
* main函数创建两个管道，并用fork生成一个子进程
* 客户端作为父进程运行，服务器则作为子进程运行
* 第一个管道用于从客户向服务器发送路径名
* 第二个管道用于从服务器向客户发送该文件的内容
*
* cin --客户端写pipe1[1]-----pipe1[0]服务器读
*       服务器写pipe2[1]-----pipe2[0]客户端读
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define FIFO1 "/tmp/fifo.1"
#define FIFO2 "/tmp/fifo.2"


//客户端从rfd中读取文件的内容，向wfd中写入文件的名字
void client(int rfd, int wfd)
{
    char fileName[1024];
    char fileContent[2048];

    memset(fileName, 0, 1024);
    memset(fileContent, 0, 2048);
    
    printf("输入文件名字：");
    //从标准输入输入文件的名字
    fgets(fileName, 1024, stdin);

    int len = strlen(fileName);
    if(fileName[len-1] == '\n')
        len--;

    //向wfd中写入文件的名字
    write(wfd, fileName, len);
    printf("fileName = %s\n", fileName);
    //从rfd中读取文件的内容
    int n;
    while((n = read(rfd, fileContent, 2048)) > 0){
        printf("client receive the content is: %s", fileContent);
    }

    close(rfd);
    close(wfd);
}

//主函数
int main()
{
    int writefd = open(FIFO1, O_WRONLY, 0);
    int readfd = open(FIFO2, O_RDONLY, 0);

    client(readfd, writefd);

    unlink(FIFO1);
    unlink(FIFO2);

    return 0;
}

