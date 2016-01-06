/*************************************************************************
	> File Name: pipe1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月20日 星期日 19时48分57秒
 ************************************************************************/

#include<iostream>
#include <unistd.h>
#include <cstdlib>
#include <fcntl.h>
#include <string>
#include <sys/wait.h>
#include <string.h>
using namespace std;

/*
1:父进程创建一个管道, 0-read, 1-write
2:父进程创建一个子进程
3:让父进程向管道中写入信息，子进程从管道读取信息；从标准输入写入到管道中
4:子进程将读取的信息输出到标准输出上面
*/

int main()
{
    int pipefd[2];
    char buff[1024];
    memset(buff, 0, 1024);

    int ret = pipe(pipefd);
    if(ret != 0){
        cerr << "pipe error..." << endl;
        exit(-1); 
    }

    pid_t pid = fork();
    if(pid < 0){
        cerr << "fork error..." << endl;
        exit(-1);
    }
    else if(pid == 0){
        //关闭管道的写端
        close(pipefd[1]);
        int ret = 0;
        cout << "This is child process...." << endl;
        while(1){
            ret  = read(pipefd[0], (void *)buff, 1024);
            if(ret == 0){
                cout << "end of read.." << endl;
                exit(0);
            }
            cout << "child read: "; 
            cout << buff << endl;
            memset(buff, 0, 1024);
        }
        close(pipefd[0]);
    }
    else if(pid > 0){
        close(pipefd[0]);
        cout << "This is parent process...." << endl;
        while(cin.getline(buff, 1024)){
            cout << "parent write: ";
            cout << buff << endl;

            write(pipefd[1], buff, 1024);
            memset(buff, 0, 1024);
        }
        close(pipefd[1]);
        wait(NULL);
    }
    exit(0);
}
