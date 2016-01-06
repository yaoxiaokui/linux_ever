/*************************************************************************
	> File Name: int_quit_signal.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月16日 星期三 21时48分22秒
 ************************************************************************/

#include <iostream>
#include <signal.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;

void handler(int num)
{
    cout << "parent recvive the signal is " << num << endl;
    if(num == SIGQUIT){
        cout << "parent receive the signal of quit.." << endl;
        exit(0);
    }
}

void child_handler(int num)
{
    cout << "child receive the signal is " << num << endl;
    if(num == SIGQUIT){
        cout << "child receive the signal of quit.." << endl;
        exit(0);
    }
    kill(getppid(), SIGINT);//向父进程发送信号
    alarm(2);
}
int main(int argc, char *argv[])
{
    //注册中断信号SIGINT
    signal(SIGINT, handler);
    signal(SIGQUIT, handler);
    pid_t pid = fork();
    if(pid < 0){
        cout << "fork error..." << endl;
        exit(-1);
    }
    if(pid == 0){
       signal(SIGALRM, child_handler);
       signal(SIGQUIT, child_handler);
       alarm(2);
       cout << "this is child process..." << endl;
        while(1){
            pause();
        }
        exit(0);
    }
    cout << "main process is waiting for the signal of SIGINT and SIGQUIT..." << endl;
    while(1){
        pause();
    }
    cout << "main process exit.." << endl;
    exit(0);
}
