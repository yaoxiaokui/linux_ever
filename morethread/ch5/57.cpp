/*************************************************************************
	> File Name: 57.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月13日 星期五 11时31分43秒
 ************************************************************************/

#include<iostream>
#include <pthread.h>

using namespace std;
int count = 0;

void *threadA(void *x)
{
    cout << "ThreadA:";
    count += 2;
    cout << count << endl;
}

void *threadB(void *x)
{
    cout << "ThreadB:";
    count += 4;
    cout << count << endl;
}

int main()
{
    pthread_t ThreadA;
    pthread_t ThreadB;
    pthread_create(&ThreadB, NULL, threadB, NULL);
    pthread_create(&ThreadA, NULL, threadA, NULL);

    pthread_join(ThreadA, NULL);
    pthread_join(ThreadB, NULL);
    return 0;
}
