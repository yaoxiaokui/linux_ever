/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月14日 星期一 16时13分21秒
 ************************************************************************/

#include <cstdlib>
#include <string.h>
#include "MyThread.h"

using namespace std;

void *thread_fun(void * arg)
{
    cout << "this is thread routine..." <<  endl;

    return NULL;
}


int main(int argc, char *argv[])
{
    int i = 0, num = 0;

    if (argc != 2){
        cout << "input the number of thread object you want to create...." << endl;
        exit(-1);
    }
    
    num = atoi(argv[1]);
    MyThread thread[num];
    
    cout << "I will create " << num << " threads." << endl;
    for (i = 0; i < num; ++i){
        thread[i].set_name("thread");
    }

    for(i = 0; i < num; ++i){
        thread[i].run(thread_fun, NULL);
        cout << thread[i].get_name() << " pid is " << thread[i].get_pid() <<  " is running.." << endl;
    } 

    for(i = 0; i < num; ++i){
        thread[i].join();
    } 
    
    cout << "main thread exit....." << endl;

    exit(0);
}

