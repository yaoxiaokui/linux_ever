/*************************************************************************
	> File Name: posix_queue.h
	> Author: 
	> Mail: 
	> Created Time: 2015年12月18日 星期五 09时48分34秒
 ************************************************************************/

#ifndef _POSIX_QUEUE_H
#define _POSIX_QUEUE_H

#include <string>
#include <mqueue.h>
#include <errno.h>
#include <iostream>
#include <sstream>
#include <sys/stat.h>
using namespace std;


class posix_queue{
    protected:
        mqd_t PosixQueue;
        mode_t QueueMode;
        int QueueFlag;
        string QueueName;
        struct mq_attr QueueAttr;
        int QueuePriority;
        int MaximumMessage;
        int MessageSize;
        int ReceivedBytes;
        void setQueueAttr(void);
    public:
        posix_queue(void);
        posix_queue(string Qname);
        posix_queue(string Qname, int MaxMsg, int MsgSize);
        ~posix_queue();

        mode_t openMode();
        void openMode(mode_t opMode);
        
        int queueFlag(void);
        void queueFlag(int x);

        int queuePriority();
        void queuePriority(int x);

        int maxMessage();
        void maxMessage(int x);

        int messageSize();
        void messageSize(int x);

        void queueName(string name);
        string QueueName();

        bool open();
        int send(string msg);
        int recevie(string &msg);

        int remove();
        int close();
};

#endif
