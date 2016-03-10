/*************************************************************************
	> File Name: mqreceive.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月08日 星期二 21时32分58秒
 ************************************************************************/

#include <iostream>
#include <mqueue.h>
#include "./Mq_getattr.h"
#include <signal.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>

using namespace std;

mqd_t mqd;
struct mq_attr attr;
char * buff;
unsigned prio;
struct sigevent sigev;

void sig_handler(int sig)
{
    mq_notify(mqd, &sigev);
    
    int n = mq_receive(mqd, buff, attr.mq_msgsize, &prio);
    cout << "priority is " << prio;
    cout << ", receive " << n << " bytes data: " << buff << endl;
    
    memset(buff, 0, sizeof(buff));
}

int main(int argc, char* argv[])
{

    //mqd_t mqd = mq_open(argv[1], O_RDONLY|O_NONBLOCK);
    mqd = mq_open(argv[1], O_RDONLY|O_NONBLOCK);
    if(mqd < 0){
        cout << "mq_open error" << endl;
        return -1;
    }

    Mq_getattr(mqd, &attr);

    buff = new char[attr.mq_msgsize];
    
    signal(SIGUSR1, sig_handler);

    sigev.sigev_notify = SIGEV_SIGNAL;
    sigev.sigev_signo = SIGUSR1;
    mq_notify(mqd, &sigev);

    for(; ;)//不断的循环
        pause();//每次接收到信号的时候，该函数返回-1,接着进入下次


    delete [] buff;
    exit(0);
}


