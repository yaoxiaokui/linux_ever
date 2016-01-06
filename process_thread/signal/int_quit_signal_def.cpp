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

int main(int argc, char *argv[])
{
    //注册中断信号SIGINT
    signal(SIGINT, SIG_IGN);
    cout << "main process is sleeping(10s)...." << endl;
    sleep(10);
    cout << "\nthe signal has the default action and waiting the SIGITN to quit..." << endl;
    signal(SIGINT, SIG_DFL);

    sleep(100);
    cout << "main process exit.." << endl;
    exit(0);
}
