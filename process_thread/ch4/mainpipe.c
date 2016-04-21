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

    //创建两个管道.
    int pipe1[2], pipe2[2];

    int ret = pipe(pipe1);
    if(ret < 0){
        printf("pipe error\n");
        return -1;
    }

    ret = pipe(pipe2);
    if(ret < 0){
        printf("pipe error\n");
        return -1;
    }
    //创建一个子进程，作为服务器,用于读取管道1(pipe1[0])中的文件名，并将文件的内容输出到管道2的pipe2[1]中
    pid_t child_pid = fork();    
    if(child_pid < 0){
        printf("fork error\n");
        return -1;
    }
    else if(child_pid > 0){//父进程
        //关闭管道1的写，关闭管道2的读, pipe1[1], pipe2[0] 
        close(pipe1[1]);
        close(pipe2[0]);

        server(pipe1[0], pipe2[1]);
    }
    else if(child_pid == 0){//子进程
        //关闭管道1的读，关闭管道2的写, pipe1[0], pipe2[1]
        close(pipe1[0]);
        close(pipe2[1]);
        client(pipe2[0], pipe1[1]);
    }


    waitpid(child_pid, NULL, 0);//等待子进程退出
    return 0;
}

