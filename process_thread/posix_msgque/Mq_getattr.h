/*************************************************************************
	> File Name: my_mq_getattr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月08日 星期二 20时24分05秒
 ************************************************************************/

#include <iostream>
#include <mqueue.h>

using namespace std;


int Mq_getattr(mqd_t mqdes, struct mq_attr *attr)
{
    int ret = mq_getattr(mqdes, attr);
    if(ret < 0){
        cout << "mq_getattr error\n";
        return -1;
    }

    cout << "mq_attr.mq_flages(0 or O_NONBLOCK) = " << attr->mq_flags << endl;
    cout << "mq_attr.mq_maxmsg = " << attr->mq_maxmsg << endl;
    cout << "mq_attr.mq_msgsize = " << attr->mq_msgsize << endl;
    cout << "mq_attr.mq_curmsgs = " << attr->mq_curmsgs << endl;

    return 0;
}
