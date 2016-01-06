/*************************************************************************
	> File Name: MyThread.h
	> Author: 
	> Mail: 
	> Created Time: 2015年12月14日 星期一 16时23分17秒
 ************************************************************************/

#ifndef _MYTHREAD_H
#define _MYTHREAD_H

#include <iostream>
#include <pthread.h>
#include <string>

using std::string;

class MyThread{
    public:
        MyThread();
        ~MyThread();
        void set_name(string name);
        string get_name();
        pthread_t get_pid();
        void run(void *(*fun)(void *), void *arg);
        void join();
        void do_something();//not use
        friend void * thread_routine(void *arg);//not use
    private:
        pthread_t pid;
        string thread_name;
};

#endif
