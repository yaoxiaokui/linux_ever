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
    cout << "\nrecvive the signal is " << num << endl;
    if(num == SIGQUIT){
        cout << "recevie the exit signal..." << endl;
        exit(0);
    }
}
int main(int argc, char *argv[])
{
    //注册中断信号SIGINT
    signal(SIGINT, handler);
    signal(SIGQUIT, handler); 
    cout << "main process is waiting for the signal of SIGINT and SIGQUIT..." << endl;
    while(1){
        pause();
    }
    cout << "main process exit.." << endl;
    exit(0);
}
