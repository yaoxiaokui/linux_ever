/*************************************************************************
	> File Name: nonblock_connect.c
	> Author: 
	> Mail: 
	> Created Time: 2016年02月27日 星期六 22时41分44秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>

#define BUFFER_SIZE 1024

int setnonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

int nonblock_connect(const char *ip, int port, int time)
{
    int ret = 0;
    struct sockaddr_in address;
    bzero(&address, sizeof(address));

    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("socket error\n");
        return -1;
    }

    int fdopt = setnonblocking(sockfd);
    
    ret = connect(sockfd, (struct sockaddr*)&address, sizeof(address));
    if(ret == 0){
        printf("连接成功\n");
        fcntl(sockfd, F_SETFL, fdopt);
        return sockfd;
    }
    else if(errno != EINPROGRESS){
        printf("连接没有建立\n");
        return -1;
    }

    fd_set writefds;
    struct timeval timeout;

    FD_ZERO(&writefds);
    FD_SET(sockfd, &writefds);
    timeout.tv_sec = time;
    timeout.tv_usec = 0;

    ret = select(sockfd+1, NULL, &writefds, NULL, &timeout);
    if(ret <= 0){
        printf("连接超时\n");
        close(sockfd);
        return -1;
    }

    if(!FD_ISSET(sockfd, &writefds)){
        printf("在sockfd上面没有找到事件\n");
        close(sockfd);
        return -1;
    }

    //检测到写事件，则清除错误标志
    int error = 0;
    socklen_t length = sizeof(error);

    if(getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, &length) < 0){
        printf("getsockopt error\n");
        close(sockfd);
        return -1;
    }

    //error不等于0表示连接出错
    if(error != 0){
        printf("connection failed after select with the error: %d\n", error);
        close(sockfd);
        return -1;
    }
    //连接成功
    printf("connection ready after select with the socket: %d\n", sockfd);

    fcntl(sockfd, F_SETFL, fdopt);
    return sockfd;
}


int main(int argc, char *argv[])
{
    if(argc <= 2){
        printf("input: %s ip_address port_number", argv[0]);
        return -1;
    } 

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    int sockfd = nonblock_connect(ip, port, 10);
    if(sockfd < 0){
        return -1;
    }

    close(sockfd);

    return 0;
}
