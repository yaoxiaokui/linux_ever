/*************************************************************************
	> File Name: epoll_server.c
	> Author: 
	> Mail: 
	> Created Time: 2016年02月27日 星期六 16时17分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

#define MAX_EVENT_NUMBER 1024
#define BUFFER_SIZE 1024

struct fds
{
    int epollfd;
    int sockfd;
};

//设置文件描述符为非阻塞
int setnonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

//将文件描述符fd添加到内核事件表中
void addfd(int epollfd, int fd, bool oneshot)
{
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    if(oneshot)
        event.events |= EPOLLONESHOT;

    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
    setnonblocking(fd);
}

void reset_oneshot(int epollfd, int fd)
{
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET | EPOLLONESHOT;
    epoll_ctl(epollfd, EPOLL_CTL_MOD, fd, &event);
}

//处理连接套接字上的数据
void* worker(void* arg)
{
    int sockfd = ((struct fds*)arg)->sockfd;
    int epollfd = ((struct fds*)arg)->epollfd;

    printf("####start new thread to receive data on fd: %d\n", sockfd);

    char buf[BUFFER_SIZE];
    memset(buf, 0, BUFFER_SIZE);

    int ret;
    while(1){
        ret = recv(sockfd, buf, BUFFER_SIZE-1, 0);
        if(ret == 0){
            close(sockfd);
            printf("对端关闭了连接\n");
            break;
        }
        else if(ret < 0){
            if(errno == EAGAIN){
                reset_oneshot(epollfd, sockfd);
               //printf("read later\n");
                break;
            }
        }
        else{
            printf("get %d bytes data: %s\n", ret, buf);
            sleep(4);//模拟此时是正在处理数据 
        }
        memset(buf, 0, BUFFER_SIZE);
    }
    printf("####end new thread receiving data on fd: %d\n", sockfd);
}


int main(int argc, char *argv[])
{
    int i;

    if(argc <= 2){
        printf("input: %s ip_addr port_num\n", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    int ret = 0;
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &servaddr.sin_addr);
    servaddr.sin_port = htons(port);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0){
        printf("socket error\n");
        return -1;
    }

    ret = bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
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
        printf("epoll_create error\n");
        close(listenfd);
    }

    addfd(epollfd, listenfd, false);

    while(1){
        int ret = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
        if(ret < 0){
            printf("epoll_wait error\n");
            break;
        }
        for(i = 0; i < ret; ++i){
            int sockfd = events[i].data.fd;
            if(sockfd == listenfd){
                struct sockaddr_in client_address;
                socklen_t client_addresslen = sizeof(client_address);
                int connfd = accept(sockfd, (struct sockaddr*)&client_address, &client_addresslen);
                //对连接套接字注册oneshot事件
                addfd(epollfd, connfd, true);
            }
            else if(events[i].events & EPOLLIN){
                pthread_t thread;
                struct fds fds_for_new_worker;
                fds_for_new_worker.sockfd = sockfd;
                fds_for_new_worker.epollfd = epollfd;
                //启动新的进程为连接socket服务
                pthread_create(&thread, NULL, worker, (void*)&fds_for_new_worker);
            }
            else{
                printf("发生了其它情况\n");
            }
        }
    }
    close(listenfd);

    return 0;
}
