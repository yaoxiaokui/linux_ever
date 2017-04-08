/*************************************************************************
	> File Name: thread_fork.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Jun 2016 10:14:44 AM CST
 ************************************************************************/

#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
using namespace std;

//互斥锁变量
pthread_mutex_t mutex;


void prepare_fun()
{
    pthread_mutex_lock(&mutex);
}

void unlock_fun()
{
    pthread_mutex_unlock(&mutex);
}

//子线程
void * threadFun(void *arg)
{
    cout << "在创建的线程中获得互斥锁mutex， 然后睡眠5秒， 再释放该互斥锁" << endl;

    //获得互斥锁
    pthread_mutex_lock(&mutex);

    //睡眠5秒
    sleep(5);

    //释放互斥锁
    pthread_mutex_unlock(&mutex);
    cout << "子线程释放互斥锁" << endl;
}

//主函数
int main(int argc, char * argv[])
{

    //初始化互斥锁
    pthread_mutex_init(&mutex, NULL);

    pthread_t tid;
    //创建线程
    pthread_create(&tid, NULL, threadFun, NULL);

    //在父进程中的主线程中睡眠1秒，为了让创建的线程获得互斥锁
    sleep(1);

    //清理互斥锁的状态
    pthread_atfork(prepare_fun, unlock_fun, unlock_fun);

    int pid = fork();
    if(pid < 0){
        cout << "fork error" << endl;
        pthread_join(tid, NULL);
        pthread_mutex_destroy(&mutex);
        return -1;
    }
    else if(pid == 0){//子进程

        cout << "子进程，执行获得互斥锁" << endl;

        /*
        子进程从父进程继承了互斥锁mutex的状态，该互斥锁处于锁住的状态，这是由父进程中的子线程执行
        phread_mutex_lock(&mutex)引起的。因此，下面这句加锁操作会一直阻塞，尽管从逻辑上来说它是
        不应该阻塞的。
        */

        pthread_mutex_lock(&mutex);
        cout << "这句话不会执行。。。" << endl;
        pthread_mutex_unlock(&mutex);
        return 0;
    }
    else{//父进程
        wait(NULL);
    }


    pthread_join(tid, NULL);
    pthread_mutex_destroy(&mutex);


    return 0;
}

