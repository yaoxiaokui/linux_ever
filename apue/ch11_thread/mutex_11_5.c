/*************************************************************************
	> File Name: mutex_11_5.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月23日 星期三 20时41分26秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct foo{
    int f_count;
    pthread_mutex_t f_lock;

};

//创建并初始化一个带有引用计数的互斥量
struct foo * foo_alloc(void)
{
    struct foo * fp;
    
    if((fp = malloc(sizeof(struct foo))) != NULL){
        fp->f_count = 1;
        if(pthread_mutex_init(&fp->f_lock, NULL) != 0){
            free(fp);
            return NULL;
        }
    }

    return fp;
}

//对互斥量增加一个引用计数
void foo_hold(struct foo* fp)
{
    pthread_mutex_lock(&fp->f_lock);
    fp->f_count++;
    pthread_mutex_unlock(&fp->f_lock);
}


//对互斥量减少一个引用计数
void foo_rele(struct foo* fp)
{
    pthread_mutex_lock(&fp->f_lock);

    if(--fp->f_count == 0){//最后一个引用了
        printf("last the reference\n");
        pthread_mutex_unlock(&fp->f_lock);
        pthread_mutex_destroy(&fp->f_lock);
        free(fp);
    }
    else{
        pthread_mutex_unlock(&fp->f_lock);
    }
}


int main()
{
    struct foo * fp;

    if((fp = foo_alloc()) == NULL){
        printf("foo_alloc error\n");
        return -1;
    }

    printf("After foo_alloc, the fp->f_count = %d\n", fp->f_count);

    foo_hold(fp);
    printf("After foo_hold, the fp->f_count = %d\n", fp->f_count);

    foo_hold(fp);
    printf("After foo_hold, the fp->f_count = %d\n", fp->f_count);

    foo_rele(fp);
    printf("After foo_rele, the fp->f_count = %d\n", fp->f_count);

    foo_rele(fp);
    printf("After foo_rele, the fp->f_count = %d\n", fp->f_count);

    foo_rele(fp);
    printf("After foo_rele, the fp->f_count = %d\n", fp->f_count);

    return 0;
}
