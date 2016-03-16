/*************************************************************************
	> File Name: print_threadId.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月16日 星期三 21时43分38秒
 ************************************************************************/

//创建一个线程并打印该线程ID；
//打印进程的ID，并打印主线程的线程ID;


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void main_fun(char* str)
{
    printf("%s", str);
    pid_t pid = getpid();
    pthread_t threadId = pthread_self();

    printf("pid = %u, main thread id = %u (0X%x)\n", pid, (unsigned int)threadId, (unsigned int)threadId);

}

void * thread_fun()
{
    printf("thread_fun id is %u\n", (unsigned int)pthread_self());
}

int main()
{

    pthread_t thread1;

    int ret = pthread_create(&thread1, NULL, thread_fun, NULL);
    if(ret != 0){
        printf("pthread_create error\n");
        return -1;
    }

    sleep(1);
    main_fun("main thread:");

    return 0;
}

