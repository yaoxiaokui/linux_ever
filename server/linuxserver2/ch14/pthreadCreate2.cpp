/*************************************************************************
	> File Name: pthreadCreate.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Jun 2016 10:05:55 AM CST
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <iostream>
using namespace std;


//线程要执行的函数
void * thread(void * arg)
{
    int num = *(static_cast<int *>(arg));
    cout << "thread tid = " << pthread_self() << ", argc = " << num << endl;
}


//主函数
int main(int argc, char * argv[])
{
    pthread_t tids[2];
    
    //创建两个线程
    for(int i = 0; i < 2; ++i){
        int ret = pthread_create(&tids[i], NULL, thread, (void*)&i);
        if(ret != 0){
            cout << "Created thread1 error\n";
        }
    }

    //在主线程中等待两个创建的线程
    for(int i = 0; i < 2; ++i){
        int ret = pthread_join(tids[i], NULL);
        if(ret != 0){
            cout << "pthread_join error\n";
        }
        else{
            cout << "thread " << tids[i] << " exit" << endl;
        }

    }


    return 0;
}
