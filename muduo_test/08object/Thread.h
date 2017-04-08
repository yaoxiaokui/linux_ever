#ifndef _THRED_H_
#define _THRED_H_

#include <pthread.h>

class Thread
{
public:
    Thread();
    virtual ~Thread();

    void Start();
    void Join();

    void SetAutoDelete(bool autoDelte);
private:
    static void* ThreadRoutine(void* arg);
    virtual void Run() = 0;
    pthread_t threadId_;
    bool autoDelte_;//是否自动销毁
};



#endif
