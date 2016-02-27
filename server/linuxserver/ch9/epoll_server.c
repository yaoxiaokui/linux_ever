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
#define MAX_EVENT_NUMBER 1024
#define BUFFER_SIZE 10

//设置文件描述符为非阻塞
int setnonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

//将文件描述符fd添加到内核事件表中
void addfd(int epollfd, int fd, bool enable_et)
{
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;
    if(enable_et)
        event.events |= EPOLLET;

    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
    setnonblocking(fd);
}

//LT模式的工作流程
void lt(struct epoll_event * events, int number, int epollfd, int listenfd)
{
    char buf[BUFFER_SIZE];
    int i;
    for(i = 0; i < number; ++i){
        int sockfd = events[i].data.fd;
        if(sockfd == listenfd){//如果描述符是监听套接字
            struct sockaddr_in clientaddr;
            socklen_t clientaddr_len;
            int connfd = accept(sockfd, (struct sockaddr*)&clientaddr, &clientaddr_len);
            addfd(epollfd, connfd, false);//对connfd禁用et模式
        }
        else if(events[i].events & EPOLLIN){//如果不是监听套接字，则是连接套接字，如果可读则读取数据,LT模式
            printf("event trigger once\n");
            memset(buf, 0, BUFFER_SIZE);
            int ret = recv(sockfd, buf, BUFFER_SIZE-1, 0);
            if(ret <= 0){
                close(sockfd);
                continue;
            }
            printf("get %d bytes data: %s\n", ret, buf);
        }
        else{
            printf("其它情况....\n");
        }
    }
}

//ET模式的工作流程
void et(struct epoll_event * events, int number, int epollfd, int listenfd)
{
    char buf[BUFFER_SIZE];
    int i;
    for(i = 0; i < number; ++i){
        int sockfd = events[i].data.fd;
        if(sockfd == listenfd){//如果描述符是监听套接字
            struct sockaddr_in clientaddr;
            socklen_t clientaddr_len;
            int connfd = accept(sockfd, (struct sockaddr*)&clientaddr, &clientaddr_len);
            addfd(epollfd, connfd, true);//对connfd开启et模式
        }
        else if(events[i].events & EPOLLIN){//如果不是监听套接字，则是连接套接字，如果可读则读取数据,ET模式，所以要重复的读完
            printf("event trigger once");
            while(1){
                memset(buf, 0, BUFFER_SIZE);
                int ret = recv(sockfd, buf, BUFFER_SIZE-1, 0);
                if(ret < 0){
                    if((errno==EAGAIN) || (errno==EWOULDBLOCK)){//此时表示读取完毕
                        printf("read later, 此时读取完毕\n\n");
                        break;
                    }
                    close(sockfd);
                    break;   
                }
                else if(ret == 0){
                    close(sockfd);
                }
                else{
                    printf("\nget %d bytes data: %s", ret, buf);
                }
            }
        }
        else{
            printf("其它情况....\n");
        }
    }
}



int main(int argc, char *argv[])
{
    if(argc <= 3){
        printf("input: %s ip_addr port_num et or lt", argv[0]);
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

    addfd(epollfd, listenfd, true);//true表示开启ET模式

    while(1){
        int ret = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
        if(ret < 0){
            printf("epoll_wait error\n");
            break;
        }
        if(strncmp(argv[3], "lt", 2) == 0)
            lt(events, ret, epollfd, listenfd);
        else if(strncmp(argv[3], "et", 2) == 0)
            et(events, ret, epollfd, listenfd);
    }
    close(listenfd);

    return 0;
}
