/*************************************************************************
	> File Name: libevent.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Aug 2016 05:55:54 PM CST
 ************************************************************************/

#include <sys/signal.h>
#include <event.h>
#include <iostream>
using namespace std;

void signal_cb(int fd, short event, void * argc)
{
    struct event_base * base = (struct event_base*)argc;

    struct timeval delay = {2, 0};
    cout << "Caught an interrupt signal!" << endl;
    cout << "Exiting in two seconds" << endl;

    //退出事件循环
    event_base_loopexit(base, &delay);
}

void timeout_cb(int fd, short event, void * argc)
{
    cout << "timeout" << endl;


    //重新注册事件处理器
    struct event_base * base = (struct event_base*)argc;
    timeval tv = {1, 0};
    struct event  * timeout_event = evtimer_new(base, timeout_cb, NULL);
    event_add(timeout_event, &tv);
}



int main()
{
    //创建一个Rector实例
    struct event_base * base = event_init();
    //创建一个中断信号处理器
    struct event * signal_event = evsignal_new(base, SIGINT, signal_cb, base);
    //将该中断信号处理器添加到注册事件队列中
    //并将事件处理器对应的事件添加到事件多路分发器中
    event_add(signal_event, NULL);

    timeval tv = {1, 0};
    struct event  * timeout_event = evtimer_new(base, timeout_cb, base);
    //struct event  * timeout_event = evtimer_new(base, timeout_cb, NULL);
    event_add(timeout_event, &tv);

    //开启事件循环
    event_base_dispatch(base);

    event_free(timeout_event);
    event_free(signal_event);
    event_base_free(base);


    return 0;
}
