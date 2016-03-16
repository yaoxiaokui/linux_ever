/*************************************************************************
	> File Name: system.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月16日 星期三 20时50分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("执行了命令:%s\n", argv[1]);

    if(system(argv[1]) < 0){
        printf("system error\n");
        return -1;
    }

    printf("父进程退出\n");

    return 0;
}

