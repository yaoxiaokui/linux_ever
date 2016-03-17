/*************************************************************************
	> File Name: thread_join.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月17日 星期四 20时45分45秒
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>


void* fun(void* val)
{
    int num = *(int*)val;

    printf("thread %d return\n", num);
    return((void*)num);
}

void* fun3(void *val)
{
    int num = *(int*)val;

    printf("thread %d return\n", num);
    pthread_exit((void*)num);
}

int main(int argc, char**argv)
{

    pthread_t thread1, thread2, thread3;
    void* rval;

    int num1 = 1;
    int num2 = 2;
    int num3 = 3;

    pthread_create(&thread1, NULL, fun, &num1);
    pthread_create(&thread2, NULL, fun, &num2);
    pthread_create(&thread3, NULL, fun3, &num3);

    pthread_join(thread1, &rval);
    printf("thread1 return value is %d\n", (int)rval);

    pthread_join(thread2, &rval);
    printf("thread2 return value is %d\n", (int)rval);

    pthread_join(thread3, &rval);
    printf("thread3 pthread_exit the value is %d\n", (int)rval);

    return 0;
}

