/*************************************************************************
	> File Name: block_pending.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月17日 星期四 17时13分45秒
 ************************************************************************/

#include <iostream>
#include <signal.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;


void handler(int num)
{
    if(num == SIGINT){
        cout << "刚才收到了信号SIGQUIT, 取消了阻塞，收到中断信号.." << endl;
    }
    else if (num == SIGQUIT){
        //将SIGINT信号设置为非阻塞的
        sigset_t un_bset;
        sigemptyset(&un_bset);
        sigaddset(&un_bset, SIGINT);
        sigprocmask(SIG_UNBLOCK, &un_bset, NULL);
    }
}

void print_pending(sigset_t * pset)
{
    int i = 0;
    cout << "未决状态字(64位)：";
    for (i = 1; i <= 64; ++i){
        if(sigismember(pset, i))
            cout << 1;
        else
            cout << 0;
        if(i % 8 == 0){
            cout << " ";
        }
    }
    cout << endl;
}
int main()
{
    sigset_t bset;
    sigset_t pset;
    
    //设置SIGINT信号
    sigemptyset(&bset);
    sigaddset(&bset, SIGINT);

    signal(SIGINT, handler);
    signal(SIGQUIT, handler);
    //将SIGINT信号设置为阻塞的
    sigprocmask(SIG_BLOCK, &bset, NULL);

    while(1){
        //得到未决状态字
        sigpending(&pset);
        //显示未决状态字
        print_pending(&pset);

        sleep(1);
    }


    exit(0);
}
