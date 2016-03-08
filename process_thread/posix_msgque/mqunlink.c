/*************************************************************************
	> File Name: mqunlink.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月08日 星期二 19时59分47秒
 ************************************************************************/

#include <stdio.h>
#include <mqueue.h>

int  main(int argc, char* argv[])
{
    if(argc != 2){
        printf("input the name\n");
        return -1;
    }

    mq_unlink(argv[1]);

    return 0;
}
