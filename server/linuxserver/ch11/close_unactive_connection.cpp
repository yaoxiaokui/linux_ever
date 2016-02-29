/*************************************************************************
	> File Name: close_unactive_connection.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月29日 星期一 19时13分27秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <pthread.h>
#include "list_timer.h"


#define FD_LIMIT 65535
#define MAX_EVENT_NUMBER 1024
#define TIMESLOT 5

int pipefd[2];

sort_timer_lst timer_lst;//升序表来管理定时器

int epollfd = 0;

//将文件描述符设置为非阻塞
int setnonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

//注册文件描述符到epollfd
void addfd(int epollfd, int fd)
{
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
    setnonblocking(fd);
}

//信号处理函数
void sig_handler(int sig)
{
    int save_errno = errno;
    int msg = sig;
    send(pipefd[1], (char*)&msg, 1, 0);//将信号的值发送到管道中
    errno = save_errno;
}

//注册信号
void addsig(int sig)
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sig_handler;
    sa.sa_flags |= SA_RESTART;
    sigfillset(&sa.sa_mask);
    int ret = sigaction(sig, &sa, NULL);
    if(ret < 0){
        printf("sigaction error\n");
    }
}


void timer_handler()
{
    timer_lst.tick();//定时处理任务
    alarm(TIMESLOT);//触发SIGALRM信号
}

//定时器回调函数，删除非活动的连接，并关闭
void cb_func(client_data* user_data)
{
    if(!user_data)
        return;

    epoll_ctl(epollfd, EPOLL_CTL_DEL, user_data->sockfd, NULL);
    close(user_data->sockfd);
    printf("close fd %d\n", user_data->sockfd);
}

int main(int argc, char *argv[])
{
    if(argc <= 2){
        printf("input: %s ip_address port_number\n", argv[0]);
        return -1;
    } 

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));

    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0){
        printf("socket error\n");
        return -1;
    }

    int ret = bind(listenfd, (struct sockaddr*)&address, sizeof(address));
    if(ret < 0){
        printf("bind error\n");
        close(listenfd);
        return -1;
    }

    ret = listen(listenfd, 5);
    if(ret < 0){
        printf("listen error\n");
        close(listenfd);
        return -1;
    }

    struct epoll_event events[MAX_EVENT_NUMBER];
    
    int epollfd = epoll_create(5);
    if(epollfd < 0){
        close(listenfd);
        printf("epoll_create error\n");
        return -1;
    }

    addfd(epollfd, listenfd);

    ret = socketpair(PF_UNIX, SOCK_STREAM, 0, pipefd);
    if(ret < 0){
        printf("socketpair error\n");
        close(listenfd);
        return -1;
    }

    setnonblocking(pipefd[1]);//写入端
    addfd(epollfd, pipefd[0]);//读出端

    //设置信号处理函数
    addsig(SIGALRM);
    addsig(SIGTERM);

    bool stop_server = false;
    struct client_data* users = new client_data[FD_LIMIT];
    bool timeout = false;
    alarm(TIMESLOT);

    while(!stop_server){
        int number = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
        if((number < 0)&&(errno != EINTR)){
            printf("epoll_wait error\n");
            break;
        }

        for(int i = 0; i < number; ++i){
            int sockfd = events[i].data.fd;
            //如果是新的连接 
            if(sockfd == listenfd){
                struct sockaddr_in client_address;
                socklen_t client_addresslen = sizeof(client_address);
                int connfd = accept(sockfd, (struct sockaddr*)&client_address, &client_addresslen);
                if(connfd < 0){
                    continue;
                }
                addfd(epollfd, sockfd);

                users[connfd].address = client_address;
                users[connfd].sockfd = connfd;
                //创建定时器，设置其回调函数和超时时间，然后绑定定时器和用户数据，最后将定时器添加到链表timer_lst中 
                util_timer* timer = new util_timer;
                timer->user_data = &users[connfd];
                timer->cb_func = cb_func;
                time_t cur = time(NULL);
                timer->expire = cur + 3*TIMESLOT;
                users[connfd].timer = timer;
                timer_lst.add_timer(timer);
            }
            else if((sockfd == pipefd[0]) && (events[i].events & EPOLLIN)){//处理信号
                int sig;
                char signals[1024];
                ret = recv(pipefd[0], signals, sizeof(signals), 0);
                if(ret == -1)
                    continue;
                else if(ret == 0)
                    continue;
                else if(ret > 0){
                    for(int i = 0; i < ret; ++i){
                        switch(signals[i]){
                            case SIGALRM:
                                timeout = true;
                                break;
                            case SIGTERM:
                                stop_server = true;
                        }
                    }                                                               
                }
            }
            else if(events[i].events & EPOLLIN){//处理客户连接上接收到的数据
                memset(users[sockfd].buf, 0, BUFFER_SIZE);
                ret = recv(sockfd, users[sockfd].buf, BUFFER_SIZE-1, 0);
                printf("get %d bytes of client data from %d: %s", ret, sockfd, users[sockfd].buf);
                util_timer* timer = users[sockfd].timer;
                if(ret < 0){
                    if(errno != EAGAIN){
                        cb_func(&users[sockfd]);
                        if(timer)
                            timer_lst.del_timer(timer);
                    }
                }
                else if(ret == 0){
                    cb_func(&users[sockfd]);
                    if(timer)
                        timer_lst.del_timer(timer);
                }
                else{
                    if(timer){
                        time_t cur = time(NULL);
                        timer->expire = cur + 3*TIMESLOT;
                        printf("adjust timer once\n");
                        timer_lst.adjust_timer(timer);
                    }
                }
            }
            else{
                printf("其它情况\n");
            }
        }

        if(timeout){
            timer_handler();
            timeout = false;
        }
    }

    close(listenfd);
    close(pipefd[1]);
    close(pipefd[0]);
    delete [] users;

    return 0;
}
