/*************************************************************************
	> File Name: SigleInstance.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Jun 2016 06:44:44 PM CST
 ************************************************************************/

#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;


//只能生成一个类对象的类
class SigleInstance
{
public:
    //指向类的一个实例对象
    static SigleInstance * instance;

private:
    //私有的构造函数
    SigleInstance(){cout << "执行SigleInstance 构造函数" << endl;}
public:
    //创建一个实例对象
    static SigleInstance * getSigleInstance(){
        return instance;
    }
};


//初始化静态成员变量,此时直接创建一个实例对象
SigleInstance * SigleInstance::instance = new SigleInstance();


//线程要执行的函数
void * threadFun(void *arg)
{
    SigleInstance * instance = SigleInstance::getSigleInstance();
    cout << "theread" << dec << pthread_self() << ", instance's address = " << hex << instance << endl;

    pthread_exit(NULL);
}

//测试函数
int main()
{
    cout << "main start..." << endl;

    const int NUM = 3;
    pthread_t threadId[NUM];

    //创建NUM个线程
    for(int i = 0; i < NUM; ++i){
        pthread_create(&threadId[i], NULL, threadFun, NULL);
    }

    for(int i = 0; i < NUM; ++i){
        pthread_join(threadId[i], NULL);
    }

    return 0;
}
