/*************************************************************************
	> File Name: testprocesspoll.c
	> Author: 
	> Mail: 
	> Created Time: Thu 16 Jun 2016 08:39:21 AM CST
 ************************************************************************/

#include <stdio.h>
#include "processpol.h"

int main()
{
    //进程池中创建6个子进程
    processpool<int> *poll = processpool<int>::create(1, 6);

    poll->run();


    return 0;
}
