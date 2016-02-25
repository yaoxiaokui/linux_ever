/*************************************************************************
	> File Name: practice_91.c
	> Author: 
	> Mail: 
	> Created Time: 2016年02月24日 星期三 15时38分01秒
 ************************************************************************/
/*
能够同时接收普通数据和带外数据
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <poll.h>
#include <errno.h>

#define OPEN_MAX 1024

int do_poll(int listenfd)
{
    int connfd, sockfd;
    struct sockaddr_in cliaddr;
    socklen_t cliaddrlen = sizeof(cliaddr);

    struct pollfd clientfds[1024];
    int maxi;
    int i;
    int nready;

    //添加监听文件描述符
    clientfds[0].fd = listenfd;
    clientfds[0].events = POLLIN;
    //初始化客户连接文件描述符
    for(i = 1; i < OPEN_MAX; ++i){
        clientfds[i].fd = -1;
    }

    maxi = 0;

    for(; ;){
        //获取就绪的文件描述符的个数
        nready = poll(clientfds, maxi+1, -1);
        if(nready == -1){
            printf("poll error\n");
            return -1;
        }
        //测试监听文件描述符是否就绪好
        if(clientfds[0].revents & POLLIN){
            //接受新的连接
            connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddrlen);
            if(connfd == -1){
                if(errno == EINTR)
                    continue;
                else{
                    printf("accept error\n");
                    return -1;
                }
            }

            printf("接受新的客户连接:%s:%d\n", inet_ntoa(cliaddr.sin_addr), cliaddr.sin_port);
            //将新的连接添加到数组中
            for(i = 1; i < OPEN_MAX; ++i){
                if(clientfds[i].fd < 0){
                    clientfds[i].fd = connfd;
                    break;
                }
            }

            if(i == OPEN_MAX){
                printf("too many clients\n");
                return -1;
            }

            clientfds[i].events = POLLIN;
            //记录客户连接套接字的个数
            maxi = (i > maxi ? i : maxi);

            if(--nready <= 0)
                continue;
        }

        //不是监听套接字就绪
        //处理客户连接，处理连接套接字
        handle_connectin(clientfds, maxi);
    }
    
}

int main(int argc, char *argv[])
{
    if(argc <= 2){
        printf("%s ip_address port_number\n", argv[0]);
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
    
    //socket
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0){
        printf("socket error\n");
        return -1;
    }

    //bind
    ret = bind(listenfd, (struct sockaddr *)&address, sizeof(address));
    if(ret != 0){
        printf("bind error\n");
        return -1;
    }

    //listen
    ret = listen(listenfd, 5);
    if(ret != 0){
        printf("listen error\n");
        return -1;
    }

    do_poll(listenfd);

    close(listenfd);

    return 0;
}
