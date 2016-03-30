/*************************************************************************
	> File Name: pthread_attr_setdepatchstate.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月30日 星期三 20时01分08秒
 ************************************************************************/

//查看创建线程的默认属性中的分离状态信息
#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

pthread_attr_t attr1;
pthread_attr_t attr2;


void * fun1(void *arg)
{
    cout << "thread1: " << pthread_self();
    int detachstate = -1;
    pthread_attr_getdetachstate(&attr1, &detachstate);
    cout << ", detachstate is " << detachstate << endl;
}

void * fun2(void *arg)
{
    cout << "thread2: " << pthread_self();
    int detachstate = -1;
    pthread_attr_getdetachstate(&attr2, &detachstate);
    cout << ", detachstate is " << detachstate << endl;
}

int main()
{

    pthread_t t_id1, t_id2;
    //初始化线程属性对象
    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);

    //pthread_attr_setdetachstate(&attr1, PTHREAD_CREATE_JOINABLE);//PTHREAD_CREATE_JOINABLE的值为0,不设置默认为该值
    pthread_attr_setdetachstate(&attr2, PTHREAD_CREATE_DETACHED);//PTHREAD_CREATE_DETACHED的值为1

    pthread_create(&t_id1, &attr1, fun1, NULL);
    pthread_create(&t_id2, &attr2, fun2, NULL);
    
    sleep(1);

    pthread_attr_destroy(&attr1);
    pthread_attr_destroy(&attr2);

    return 0;
}


