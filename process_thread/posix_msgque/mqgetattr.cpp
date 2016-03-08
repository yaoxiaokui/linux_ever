/*************************************************************************
	> File Name: mqgetattr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月08日 星期二 20时33分25秒
 ************************************************************************/

#include <iostream>
#include "Mq_getattr.h"
using namespace std;

int main(int argc, char* argv[])
{
    mqd_t mqd;
    struct mq_attr attr;

    mqd = mq_open(argv[1], O_RDONLY);

    Mq_getattr(mqd, &attr);

    mq_close(mqd);


    return 0;
}

