/*************************************************************************
	> File Name: create_join.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月16日 星期三 10时41分19秒
 ************************************************************************/

#include<iostream>
#include <unistd.h>
#include <pthread.h>
#include <cstdlib>

using namespace std;

void *task1(void *a)
{
    cout << "This is threadA..." << "thread id is " << pthread_self() << endl;
    sleep(2);
    cout << "threadA exit.." << endl;
}

void *task2(void *b)
{
    cout << "This is threadB..." << "thread id is " << pthread_self() << endl;
    sleep(2);
    cout << "ThreadB exit.." << endl;
}
int main()
{
    int ret;
    pthread_t threadA, threadB;

    ret = pthread_create(&threadA, NULL, task1, NULL);
    if(ret != 0){
        cout << "pthread_create error..." << endl;
        exit(-1);
    }
    ret = pthread_create(&threadB, NULL, task2, NULL);
    if(ret != 0){
        cout << "pthread_create error..." << endl;
        exit(-1);
    }

    ret = pthread_join(threadA, NULL);
    if(ret != 0){
        cout << "pthread_create error..." << endl;
        exit(-1);
    }
    ret = pthread_join(threadB, NULL);
    if(ret != 0){
        cout << "pthread_create error..." << endl;
        exit(-1);
    }

    cout << "main thread exit..." << endl;
    exit(0);
}
