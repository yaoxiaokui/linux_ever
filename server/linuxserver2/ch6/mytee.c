/*************************************************************************
	> File Name: mytee.c
	> Author: 
	> Mail: 
	> Created Time: Mon 30 May 2016 05:14:02 PM CST
 ************************************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char* argv[])
{
    if(argc < 2){
        printf("input: %s FileName\n", argv[0]);
        return -1;
    }

    //先创建一个文件
    int filefd = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if(filefd < 0){
        printf("create %s error\n",  argv[1]);
    }


    //用于标准输出
    int pipefd_stdout[2];
    pipe(pipefd_stdout);

    //用于输出到文件
    int pipefd_file[2];
    pipe(pipefd_file);

    //标准输入----->pipefd_stdout[1]
    splice(STDIN_FILENO, NULL, pipefd_stdout[1], NULL, 32768, SPLICE_F_MOVE | SPLICE_F_MORE);

    //pipefd_stdout[0]----->pipefd_file[1]
    tee(pipefd_stdout[0], pipefd_file[1], 32768, SPLICE_F_NONBLOCK);

    //pipefd_file[0]----->filefd
    splice(pipefd_file[0], NULL, filefd, NULL, 32768, SPLICE_F_MOVE | SPLICE_F_MORE);

    //pipefd_stdout[0]---->标准输出
    splice(pipefd_stdout[0], NULL, STDOUT_FILENO, NULL, 32768, SPLICE_F_MOVE | SPLICE_F_MORE);


    //关闭文件描述符
    close(filefd);
    close(pipefd_stdout[0]);
    close(pipefd_stdout[1]);
    close(pipefd_file[0]);
    close(pipefd_file[1]);

    return 0;
}
