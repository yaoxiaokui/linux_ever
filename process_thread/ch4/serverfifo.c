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

//服务器从rfd中读取文件的名字，向wfd中写入文件的内容
void server(int rfd, int wfd)
{
    char fileName[1024];
    char fileContent[2048];

    memset(fileName, 0, 1024);
    memset(fileContent, 0, 2048);

    //从rfd中读取文件的名字，
    int n = read(rfd, fileName, 1024);
    fileName[n] = 0;
    printf("server receive the file name is %s\n", fileName);

    int filefd = open(fileName, O_RDONLY);//打开文件
    if(filefd < 0){
        printf("open error\n");
        return;
    }
    else{//读取文件的内容，并写入到wfd中
         //读取文件的内容到fileContent中
         int num = 0;
         while((num = read(filefd, fileContent, 2048)) > 0){
            printf("server read the fileContent is: %s", fileContent);
            //将fileContent中的内容写入到wfd中
            write(wfd, fileContent, num);
        }
    }

    close(filefd);
    close(rfd);
    close(wfd);

}

//主函数
int main()
{
    int ret = mkfifo(FIFO1, S_IRUSR|S_IWUSR);
    if(ret < 0 && errno != EEXIST){
        printf("mkfifo error\n");
        return -1;
    }

    ret = mkfifo(FIFO2, S_IRUSR|S_IWUSR);
    if(ret < 0 && errno != EEXIST){
        printf("mkfifo error\n");
        unlink(FIFO1);
        return -1;
    }

    //关闭管道1的写，关闭管道2的读, pipe1[1], pipe2[0] 
    int readfd = open(FIFO1, O_RDONLY, 0);
    int writefd = open(FIFO2, O_WRONLY, 0);
    server(readfd, writefd);

    return 0;
}

