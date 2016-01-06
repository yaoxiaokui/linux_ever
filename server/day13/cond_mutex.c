/*************************************************************************
    > File Name: threadbase.c
    > Author: 
    > Mail:  
    > Created Time: 2015年12月04日 星期五 17时44分38秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>


#define CUSTOM_COUNT 2
#define PRODUCT_COUNT 3 

int nNum, nLoop;
int g_count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
 
void *consume(void *arg)
{
	while(1){
		pthread_mutex_lock(&mutex);
        while(g_count == 0){//醒来以后需要重新判断条件是否满足,如果不满足，再次等待
            printf("consume is waiting: %lu\n", pthread_self());
            pthread_cond_wait(&cond, &mutex);
		}
        printf("consume is %lu, g_count is %d\n", pthread_self(), g_count);
        g_count--;
	    pthread_mutex_unlock(&mutex);	
        sleep(1);
	}
	pthread_exit(NULL);
}

void *produce(void *arg)
{
    while(1){
        pthread_mutex_lock(&mutex);
        if(g_count >= 10){
            printf("产品太多，休眠1秒\n");
            pthread_mutex_unlock(&mutex);
            sleep(1);
            continue;
        }
   //不用解锁再上锁，因为如果大于10，会解锁，但是会continue,不会执行下面的语句，会重新从头开始，上锁； 
        printf("start produce the product\n");
        g_count++;
        printf("produce is %lu, g_count is %d\n", pthread_self(), g_count);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
	pthread_exit(NULL);
}

int main()
{
	int i = 0;
	pthread_t tidCustom[CUSTOM_COUNT];
	pthread_t tidProduce[PRODUCT_COUNT];
	

	for (i = 0; i < CUSTOM_COUNT; ++i){
		pthread_create(&tidCustom[i], NULL, consume, NULL);
	}

	sleep(3);

	for (i = 0; i < PRODUCT_COUNT; ++i){
		pthread_create(&tidProduce[i], NULL, produce, NULL);
	}

	for (i = 0; i < CUSTOM_COUNT; ++i){
		pthread_join(tidCustom[i], NULL);
	}

	for (i = 0; i < PRODUCT_COUNT; ++i){
		pthread_join(tidProduce[i], NULL);
	}
	printf("parent exit\n");
	exit(0);
}

