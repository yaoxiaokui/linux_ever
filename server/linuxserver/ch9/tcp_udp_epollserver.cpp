/*************************************************************************
	> File Name: tcp_udp_epollserver.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月28日 星期日 19时27分24秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>

using namespace std;

#define MAX_EVENT_NUMBER 1024
#define TCP_BUFFER_SIZE 512
#define UDP_BUFFER_SIZE 1024

int setnonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}


void addfd(int epollfd, int fd)
{
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
    setnonblocking(fd);
}

int main(int argc, char * argv[])
{
    if(argc <= 2){
        printf("input: %s ip_address port_num", argv[0]);
        return -1;
    } 

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    int ret = 0;

    struct sockaddr_in address;
    bzero(&address, sizeof(address));

    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);
//创建tcp套接字
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0){
        printf("socket error\n");
        return -1;
    }

    ret = bind(listenfd, (struct sockaddr*)&address, sizeof(address));
    if(ret < 0){
        printf("bind error\n");
        return -1;
    }

    ret = listen(listenfd, 5);
    if(ret < 0){
        printf("listen error\n");
        return -1;
    }

//创建UDP套接字
    bzero(&address, sizeof(address));

    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);

    int udpfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(listenfd < 0){
        printf("socket error\n");
        return -1;
    }

    ret = bind(udpfd, (struct sockaddr*)&address, sizeof(address));
    if(ret < 0){
        printf("bind error\n");
        return -1;
    }

   /***********************************************************/ 

    struct epoll_event events[MAX_EVENT_NUMBER];
    int epollfd = epoll_create(5);
    if(epollfd < 0){
        printf("epoll_create error\n");
        return -1;
    }

    addfd(epollfd, listenfd);
    addfd(epollfd, udpfd);

    while(1){
        int number = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
        if(number < 0){
            printf("epoll_wait error\n");
            break;
        }

        for(int i = 0; i < number; ++i){
            int sockfd = events[i].data.fd;
            if(sockfd == listenfd){//tcp 套接字
                struct sockaddr_in client_address;
                socklen_t client_addresslen = sizeof(client_address);
                int connfd = accept(sockfd, (struct sockaddr*)&client_address, &client_addresslen);
                if(connfd < 0){
                    printf("accept error\n");
                    continue;
                }

                addfd(epollfd, connfd);
            }
            else if(sockfd == udpfd){//udp 套接字
                char buf[UDP_BUFFER_SIZE];
                memset(buf, 0, UDP_BUFFER_SIZE);
                struct sockaddr_in client_address;
                socklen_t client_addresslen = sizeof(client_address);
                ret = recvfrom(udpfd, buf, UDP_BUFFER_SIZE-1, 0, (struct sockaddr*)&client_address, &client_addresslen);
                if(ret > 0)
                    sendto(udpfd, buf, UDP_BUFFER_SIZE-1, 0, (struct sockaddr*)&client_address, client_addresslen);
            }
            else if(events[i].events & EPOLLIN){
                char buf[TCP_BUFFER_SIZE];
                while(1){
                    memset(buf, 0, TCP_BUFFER_SIZE);
                    ret = recv(sockfd, buf, TCP_BUFFER_SIZE-1, 0);
                    if(ret < 0){
                        if((errno == EAGAIN) && (errno == EWOULDBLOCK)){
                            break;
                        }
                        close(sockfd);
                        break;
                    }
                    else if(ret == 0){
                        close(sockfd);
                    }
                    else{
                        send(sockfd, buf, ret, 0);
                    }
                }
            }
            else{
                printf("发生了其它的情况\n");
            }
        }
    }

    close(listenfd);

    return 0;
}
