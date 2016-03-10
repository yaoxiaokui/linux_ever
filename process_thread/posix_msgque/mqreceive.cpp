/*************************************************************************
	> File Name: mqreceive.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月08日 星期二 21时32分58秒
 ************************************************************************/

#include <iostream>
#include <mqueue.h>
#include "./Mq_getattr.h"

using namespace std;

int main(int argc, char* argv[])
{
    struct mq_attr attr;
    char * buff;
    unsigned prio;

    //mqd_t mqd = mq_open(argv[1], O_RDONLY|O_NONBLOCK);
    mqd_t mqd = mq_open(argv[1], O_RDONLY|O_NONBLOCK);
    if(mqd < 0){
        cout << "mq_open error" << endl;
        return -1;
    }

    Mq_getattr(mqd, &attr);

    buff = new char[attr.mq_msgsize];
    
    int n = mq_receive(mqd, buff, attr.mq_msgsize, &prio);
    cout << "priority is " << prio;
    cout << ", receive " << n << " bytes data: " << buff << endl;

    delete [] buff;

    return 0;
}

