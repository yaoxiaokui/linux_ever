/*************************************************************************
	> File Name: MyThread.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月14日 星期一 16时31分43秒
 ************************************************************************/

#include "MyThread.h"
using namespace std;

MyThread::MyThread()
{
    
}

MyThread::~MyThread()
{
    pthread_join(pid, NULL);
}

void MyThread::set_name(string name)
{
    thread_name = name;
}

string MyThread::get_name()
{
    return thread_name;
}

pthread_t MyThread::get_pid()
{
    return pid;
}
void MyThread::run(void *(*fun)(void *), void *arg)
{
    pthread_create(&pid, NULL, fun, arg);
}

void MyThread::join()
{
    pthread_join(pid, NULL);
}

/*not use*/
void MyThread::do_something()
{
   cout << "thread id is " << pid << ", name is " << thread_name << endl;
}

/*not use*/
void * thread_routine(void *arg)
{
    MyThread * pthread;
    pthread = static_cast<MyThread *>(arg);
    pthread->do_something();

    return NULL;
}
