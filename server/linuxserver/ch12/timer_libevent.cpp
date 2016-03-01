/*************************************************************************
	> File Name: timeout_libevent.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月01日 星期二 19时23分37秒
 ************************************************************************/

#include <iostream>
#include <event.h>

using namespace std;


void onTime(int sock, short event, void* arg)
{
    cout << "Hello world\n";

    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    //添加定时事件
    event_add((struct event*)arg, &tv);
}

int main()
{
    //初始化
    event_init();

    struct event evTime;
    //设置定时事件
    evtimer_set(&evTime, onTime, &evTime);

    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    //添加定时事件
    event_add(&evTime, &tv);

    //事件循环
    event_dispatch();

    return 0;
}


