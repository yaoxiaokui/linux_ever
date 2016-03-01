/*************************************************************************
	> File Name: timer2_libevent.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月01日 星期二 19时41分19秒
 ************************************************************************/

#include <iostream>
using namespace std;

#include <event.h>

struct event ev;
struct timeval tv;

void time_cb(int fd, short event, void* argc)
{
    cout << "timer wakeup\n";
    event_add(&ev, &tv);

}

int main()
{
    struct event_base* base = event_init();
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    evtimer_set(&ev, time_cb, NULL);
    event_add(&ev, &tv);
    event_base_dispatch(base);

    return 0;
}
