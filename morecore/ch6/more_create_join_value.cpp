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

void *task(void *a)
{
    int i = 0;
    int * loop;
    loop = static_cast<int*> (a);
    for (i = 0; i < *loop; ++i){
        cout <<  i+1 << ": This is thread..." << "thread id is " << pthread_self() << endl;
        sleep(1);
    } 
    cout << "thread exit.." <<  pthread_self() << endl;
}


int main(int argc, char *argv[])
{
    int ret;
    int i = 0;
    if(argc != 2){
        cout << "You must input the number of thread you want to create..." << endl;
        exit(-1);
    }
    int thread_num = atoi(argv[1]);
    pthread_t threadId[thread_num];

	for (i = 0; i < thread_num; ++i){
		ret = pthread_create(&threadId[i], NULL, task, (void *)&thread_num);
	    if(ret != 0){
	        cout << "pthread_create error..." << endl;
	        exit(-1);
	    }			
	}
    
    for (i = 0; i < thread_num; ++i){
		ret = pthread_join(threadId[i], NULL);
	    if(ret != 0){
	        cout << "pthread_create error..." << endl;
	        exit(-1);
	    }			
	}
    
    cout << "main thread exit..." << endl;
    exit(0);
}
