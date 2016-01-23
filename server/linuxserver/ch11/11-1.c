/*************************************************************************
	> File Name: 11-1.c
	> Author: 
	> Mail: 
	> Created Time: 2016年01月22日 星期五 09时34分20秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>

int timeout_connect(const char * ip, int port, int time)
{
    int ret = 0;

    struct sockaddr_in address;
    bzero(&address, sizeof(address));

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, ip, &address.sin_addr);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd <= 0){
        printf("socket error\n");
        return -1;
    }

    struct timeval timeout;
    timeout.tv_sec = time;
    timeout.tv_usec = 0;

    socklen_t len = sizeof(timeout);

    ret = setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO,&timeout, len);
    if(ret < 0){
        printf("setsockopt error\n");
        return -1;
    }

    ret = connect(sockfd, (struct sockaddr *)&address, sizeof(address));
    if(ret == -1){
        if(errno == EINPROGRESS){
            printf("connectint timeout\n");
            return -1;
        }
        printf("connect error\n");
        return -1;
    }

    return sockfd;
}

int main(int argc, char *argv[])
{
    if(argc <= 2){
        printf("Please input: %s ip_address port_num\n", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);
    int sockfd = timeout_connect(ip, port, 10);
    if(sockfd <= 0){
        return -1;
    }
    else{
        printf("client socket is %d\n", sockfd);
        const char * data = "linux_ever";
        int ret = send(sockfd, data, strlen(data), 0);
        printf("client send %d bytes data : %s\n", ret, data);
    } 

    return 0;
}
