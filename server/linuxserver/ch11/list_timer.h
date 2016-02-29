/*************************************************************************
	> File Name: list_timer.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月29日 星期一 15时56分56秒
 ************************************************************************/

#ifndef _LIST_TIMER_H
#define _LIST_TIMER_H

#include <time.h>
#include <stdio.h>

#define BUFFER_SIZE 64

//用户数据：客户端socket地址，socket文件描述符，读缓存和定时器
struct client_data
{
    sockaddr_in address;
    int sockfd;
    char buf[BUFFER_SIZE];
    util_timer *timer;
};

//定时器类
class util_timer
{
    public:
        util_timer():prev(NULL), next(NULL){}

    public:
        time_t expire;//任务的超时时间，这里是绝对时间
        void (*cb_func)(client_data*);//任务回调函数
        client_data * user_data;//回调函数处理的客户数据，由定时器的执行者传递给回调函数
        util_timer* prev;
        util_timer* next;
};

//定时器链表类，升序，双向链表，有头结点和尾结点
class sort_timer_lst
{
    private:
        util_timer* head;
        util_timer* tail;
    public:
        sort_timer_lst():head(NULL), tail(NULL){}
        ~sort_timer_lst();
        void add_timer(util_timer* timer);//将目标定时器timer添加到链表中
        void adjust_timer(util_timer* timer);//调整对应的定时器在链表中的位置
        void del_timer(util_timer* timer);//将目标定时器timer从链表中删除
        void tick();//处理链表上到期的任务
    private:
        void add_timer(util_timer* timer, util_timer* lst_head);//将目标定时器添加到结点lst_head后面的部分链表中
};

sort_timer_lst::~sort_timer_lst()
{
    util_timer* tmp = head;
    while(tmp){
        head = tmp->next;
        delete tmp;
        tmp = head;
    }
}

//将目标定时器添加到链表中
void sort_timer_lst::add_timer(util_timer* timer)
{
    if(!timer){
        return;
    }

    if(!head){//如果是空链表 head = tail = NULL;
        head = tail = timer;
        return;
    }
    
    //如果目标定时器的值是最小的，则添加到链表的头部之前
    if(timer->expire < head->expire){
        timer->next = head;
        timer->prev = NULL;
        head->prev = time;
        head = timer;
        return;
    }
    //目标定时器不是最小的，则把它放到head后面的链表中
    add_timer(timer, head);
}


void sort_timer_lst::adjust_timer(util_timer* timer)
{
    if(!timer){
        return;
    }

    util_timer* tmp = timer->next;
    if(!tmp || (timer->expire < tmp->expire)){
        return;
    }
    //如果目标定时器是链表的头节点，则将该定时器从链表中取出并重新插入链表
    if(timer == head){
        head = head->next;
        head->prev = NULL;
        timer->next = NULL;
        add_timer(timer, head);
    }
    else{//目标定时器不是链表的头结点
        timer->prev->next = timer->next;
        timer->next->prev = timer->prev;
        add_timer(timer, timer->next);
    }
}

void sort_timer_lst::del_timer(util_timer* timer)
{
    if(!timer)
        return;

    //如果只有一个定时器
    if((timer == head) && (timer == tail)){
        delete timer;
        head = NULL;
        tail = NULL;
        return;
    }
    
    //有多余两个定时器，并且目标定时器是头结点
    if(timer == head){
        head = head->next;
        head->prev = NULL;
        delete timer;
        return;
    }
    //有多于两个定时器,并且目标定时器是尾结点
    if(timer == tail){
        tail = tail->prev;
        tail->next = NULL;
        delete timer;
        return;
    }
    //如果有多于两个定时器，并且目标定时器在中间，删除目标定时器
    timer->prev->next = timer->next;
    timer->next->prev = timer->prev;
    delete timer;
}

void sort_timer_lst::tick()
{
    if(!head)
        return;

    printf("timer tick\n");
    time_t cur = time(NULL);
    util_timer* tmp = head;
    
    while(tmp){
        if(cur < tmp->expire)
            break;

        //定时时间到，则执行回调函数
        tmp->cb_func(tmp->user_data);
        //执行完回调函数之后，将定时器删除
        head = tmp->next;
        if(head){
            head->prev = NULL;
        }
        delete timer;
        tmp = head;
    }
}

void sort_timer_lst::add_timer(util_timer* timer, util_timer* lst_head)
{
    util_timer* prev = lst_head;
    util_timer* tmp = prev->next;

    while(tmp){
        if(timer->expire < tmp->expire){
            prev->next = timer;
            timer->prev = prev;
            timer->next = tmp;
            tmp->prev = timer;
            break;
        }
        prev = tmp;
        tmp = prev->next;
    }

    //插入到尾部
    if(!tmp){
        prev->next = timer;
        timer->prev = prev;
        timer->next = NULL;
        tail = timer;
    }
}

#endif
