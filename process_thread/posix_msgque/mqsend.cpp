/*************************************************************************
	> File Name: mqsend.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月08日 星期二 21时20分40秒
 ************************************************************************/

#include <iostream>
#include <mqueue.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc, char* argv[])
{
    //mq_send(mqdes, const char* msg_ptr, size_t msg_len, unsigned msg_prio);
    if(argc < 5){
        cout << "mqsend mq_name msg_ptr msg_len msg_prio" << endl;
        return -1;
    }
    mqd_t mqd;
    const char* ptr = argv[2];
    int msg_len = atoi(argv[3]);
    int msg_prio = atoi(argv[4]);

    mqd = mq_open(argv[1], O_RDWR);

    mq_send(mqd, ptr, strlen(ptr), msg_prio);


    return 0;
}

