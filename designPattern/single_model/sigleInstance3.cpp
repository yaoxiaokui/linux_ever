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

    //定义一个互斥锁变量
    static pthread_mutex_t instanceMutex;

private:
    //私有的构造函数
    SigleInstance(){cout << "执行SigleInstance 构造函数" << endl;}
public:
    //创建一个实例对象
    static SigleInstance * getSigleInstance(){

        //如果实例没有创建，则加锁并创建实例
        //如果实例已经创建，则直接返回该实例的指针
        if(instance == NULL){
            //获得互斥锁
            pthread_mutex_lock(&instanceMutex);

            if(instance == NULL)
                instance = new SigleInstance();

            //睡眠仅仅为了测试其它线程是否处于等待状态，真正的程序是不需要该延迟的
            sleep(3);

            //释放互斥锁
            pthread_mutex_unlock(&instanceMutex);
        }

        return instance;
    }
};


//初始化静态成员变量
SigleInstance * SigleInstance::instance = NULL;
//初始化互斥锁变量
pthread_mutex_t SigleInstance::instanceMutex = PTHREAD_MUTEX_INITIALIZER;


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
