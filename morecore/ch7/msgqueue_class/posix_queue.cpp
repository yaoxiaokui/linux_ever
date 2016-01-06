/*************************************************************************
	> File Name: posix_queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月18日 星期五 10时01分59秒
 ************************************************************************/

#include "posix_queue.h"

bool posix_queue::open()
{
    bool success = true;
    int ret;
    PosixQueue = mq_open(QueueName.c_str(), QueueFlag, QueueMode, &QueueAttr);

}
