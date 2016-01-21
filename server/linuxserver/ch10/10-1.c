/*************************************************************************
	> File Name: 10-1.c
	> Author: 
	> Mail: 
	> Created Time: 2016年01月21日 星期四 09时24分01秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <sys/epoll.h>



#define MAX_EVENT_NUMBER 1024
static int pipefd[2];

int setnonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFD);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFD, new_option);

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

void sig_handler(int sig)
{
    int save_errno = errno;
    int msg = sig;
    send(pipefd[1], (char *)&msg, 1, 0);
    errno = save_errno;
}

void addsig(int sig)
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sig_handler;
    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);
    int ret = sigaction(sig, &sa, NULL);
    if(ret < 0){
        printf("sigaction error\n");
    }
}

int main(int argc, char *argv[])
{
    if(argc <= 2){
        printf("Input: %s ip_address port_num\n", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr); 
    address.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd <= 0){
        printf("socket error\n");
        return -1;
    }

    int ret = bind(sockfd, (struct sockaddr*)&address, sizeof(address));
    if(ret < 0){
        printf("bind error\n");
        return -1;
    }

    ret = listen(sockfd, 5);
    if(ret < 0){
        printf("bind error\n");
        return -1;
    }

    struct epoll_event events[MAX_EVENT_NUMBER];
    int epollfd = epoll_create(5);
    if(epollfd < 0){
        printf("epoll_create error\n");
        return -1;
    }

    addfd(epollfd, sockfd);
    //create pipe, register the event of read on pipefd[0];

    ret = socketpair(PF_UNIX, SOCK_STREAM, 0, pipefd);
    if(ret < 0){
        printf("socketpair error\n");
        return -1;
    }

    setnonblocking(pipefd[1]);
    addfd(epollfd, pipefd[0]);

    addsig(SIGHUP);
    addsig(SIGCHLD);
    addsig(SIGTERM);
    addsig(SIGINT);

    bool stop_server = false;
    int connfd;

    while(!stop_server){
        int num = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
        if(num < 0 && errno != EINTR){
            printf("epoll error\n");
            break;
        }
        int i;
        for (i = 0; i < num; ++i){
            int fd = events[i].data.fd;

            if(fd == sockfd){
                struct sockaddr_in client_addr;
                socklen_t client_addr_len;
                connfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
                if(connfd < 0){
                    printf("accept error\n");
                    return -1;
                }
                printf("new connection\n");

                addfd(epollfd, connfd);
            }
            else if((fd == pipefd[0]) && (events[i].events & EPOLLIN)){
                int sig;
                char signals[1024];
                ret = recv(pipefd[0], signals, sizeof(signals), 0);
                if(ret == -1){
                    continue;
                }
                else if(ret == 0){
                    continue;
                }
                else{
                    int j;
                    for(j = 0; j < ret; ++j){
                        switch(signals[j]){
                            case SIGCHLD:
                                printf("signal is %d\n", signals[j]);
                                break;
                            case SIGHUP:
                                printf("signal is %d\n", signals[j]);
                                continue;
                            case SIGTERM:
                            case SIGINT:
                                printf("signal is %d\n", signals[j]);
                                stop_server = true;
                                break;
                            default:
                                printf("signal is %d\n", signals[j]);
                                break;
                        }
                    }
                }
            }
            else if(fd == connfd){
                char buffer[1024];
                memset(buffer, 0, sizeof(buffer));
                ret = recv(connfd, buffer, sizeof(buffer), 0);
                printf("recevied the data: %s\n", buffer);
            }
        }
    }
    printf("close fds\n");
    close(sockfd);
    close(pipefd[0]);
    close(pipefd[1]);


    return 0;
}
