/*************************************************************************
	> File Name: mqcreate1.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月08日 星期二 19时21分31秒
 ************************************************************************/

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int c, flags;


    flags = O_CREAT | O_RDWR;

    while((c= getopt(argc, argv, "e")) != -1){
        switch (c){
            case 'e':
                flags |= O_EXCL;
            break;
        }
    }

    if(optind != argc -1){
        printf("error\n");
        return -1;
    }

    mqd_t mqd = mq_open(argv[optind], flags, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, NULL);
    printf("mqd  = %d\n", mqd);
    if(mqd < 0){
        printf("mq_open error\n");
        return -1;
    }


    mq_close(mqd);

    return 0;
}

