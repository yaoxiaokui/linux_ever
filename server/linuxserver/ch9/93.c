/*************************************************************************
	> File Name: 93.c
	> Author: 
	> Mail: 
	> Created Time: 2016年01月19日 星期二 12时45分43秒
 ************************************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdbool.h>
#define MAX_EVENT_NUMBER 1024

#define BUFFER_SIZE 10

//set the fd to nonblock
int setnonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFD);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFD, new_option);

    return old_option;
}

void addfd(int epollfd, int fd, bool enable_et)
{
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;

    if(enable_et){
        event.events |= EPOLLET;
    }

    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);

    setnonblocking(fd);
}

//lt
void lt(struct epoll_event *events, int number, int epollfd, int listenfd)
{
    char buf[BUFFER_SIZE];
    int i;
    for(i = 0; i < number; ++i){
        int sockfd = events[i].data.fd;
        if(sockfd == listenfd){
            struct sockaddr_in client_addr;
            socklen_t client_addr_len;
            int connfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_addr_len);
            addfd(epollfd, connfd, false);
        }
        else if(events[i].events & EPOLLIN){
            printf("event trigger once\n");
            memset(buf, 0, BUFFER_SIZE);
            int ret = recv(sockfd, buf, BUFFER_SIZE-1, 0);
            if(ret < 0){
                close(sockfd);
                continue;
            }
            printf("get %d bytes of content: %s\n", ret, buf);
        }
        else{
            printf("something else happened\n");
        }
    }
}

//et
void et(struct epoll_event * events, int number, int epollfd, int listenfd)
{
    char buf[BUFFER_SIZE];
    int i;
    for(i = 0; i < number; ++i){
        int sockfd = events[i].data.fd;
        if(sockfd == listenfd){
            struct sockaddr_in client_addr;
            socklen_t client_addr_len;
            int connfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
            addfd(epollfd, connfd, true);
        }
        else if(events[i].events & EPOLLIN){
            printf("event trigger once\n");
            while(1){
                memset(buf, 0, BUFFER_SIZE);
                int ret = recv(sockfd, buf, BUFFER_SIZE-1, 0);
                if(ret < 0){
                    if((errno == EAGAIN)||(errno == EWOULDBLOCK)){
                        printf("read later\n");
                        break;
                    }
                    close(sockfd);
                    break;
                }
                else if(ret == 0){
                    close(sockfd);
                }
                else{
                    printf("get %d bytes of content: %s\n", ret, buf);
                }
            }
        }
        else{
            printf("something else heppened\n");
        }
    }
}

int main(int argc, char **argv)
{
    if(argc <= 2){
        printf("%s ip_address port_number\n", argv[0]);
        return -1;
    } 

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_port = htons(port);
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd <= 0){
        printf("socket error\n");
        return -1;
    }

    int ret = bind(listenfd, (struct sockaddr *)&address, sizeof(address));
    if(ret < 0){
        printf("bind error\n");
        return -1;
    }

    ret = listen(listenfd, 5);
    if(ret < 0){
        printf("listen error\n");
        return -1;
    }

    struct epoll_event events[MAX_EVENT_NUMBER];

    int epollfd = epoll_create(5);
    if(epollfd < 0){
        printf("epoll_create error\n");
        return -1;
    }
    
    addfd(epollfd, listenfd, true);

    while(1){
        int ret = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
        if(ret < 0){
            printf("epoll_wait error\n");
            break;
        }
        
        lt(events, ret, epollfd, listenfd);
        //et(events, ret, epollfd, listenfd);

    }
    
    close(listenfd);

    return 0;
}
