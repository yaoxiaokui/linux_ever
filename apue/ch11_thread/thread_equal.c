/*************************************************************************
	> File Name: thread_equal.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月16日 星期三 21时18分05秒
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void * fun1()
{
    printf("thread1 id is %d\n", pthread_self());
    printf("线程1退出\n");
}

void * fun2()
{
    printf("thread2 id is %d\n", pthread_self());
    printf("线程2退出\n");
}

int main()
{

    pthread_t thread1, thread2;

    printf("创建两个线程，比较两个线程id...\n");

    int ret = pthread_create(&thread1, NULL, fun1, NULL);
    if(ret != 0){
        printf("pthread_create error\n");
        return -1;
    }

    ret = pthread_create(&thread2, NULL, fun2, NULL);
    if(ret != 0){
        printf("pthread_create error\n");
        return -1;
    }

    ret = pthread_equal(thread1, thread2);
    if(ret != 0)
        printf("thread1 == thread2\n");
    else 
        printf("thread1 != thread2\n");

    sleep(2);
    printf("进程退出..\n");

    return 0;
}
