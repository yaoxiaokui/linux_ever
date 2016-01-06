/*************************************************************************
	> File Name: 61.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月14日 星期六 21时41分55秒
 ************************************************************************/

#include<iostream>
#include <pthread.h>
#include <stdlib.h>

using namespace std;

pthread_mutex_t MyLock;

void *thread(void *x)
{
    for (int i = 0; i < 10; i++){
        pthread_mutex_lock(&MyLock);
        cout << pthread_self() << " I am alive in thread 1." << " ** " << i << endl;
        pthread_mutex_unlock(&MyLock);
    }
}

void *thread2(void *x)
{
    for (int i = 0; i < 10; i++){
        pthread_mutex_lock(&MyLock);
        cout << pthread_self() << " I am alive in thread 2." << " ** " << i << endl;
        pthread_mutex_unlock(&MyLock);
    }
    
}

int main()
{
    
    pthread_t threadId1;
    pthread_t threadId2;
    pthread_mutex_init(&MyLock, NULL);

    pthread_create(&threadId1, NULL, thread, NULL);
    pthread_create(&threadId2, NULL, thread2, NULL);

    pthread_join(threadId1, NULL);
    pthread_join(threadId2, NULL);

    return 0;
}
