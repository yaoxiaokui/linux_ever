/*************************************************************************
	> File Name: timeout_connect.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月29日 星期一 15时10分06秒
 ************************************************************************/

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

using namespace std;

int timeout_connect(const char * ip, int port, int time)
{
    struct sockaddr_in serv_address;
    bzero(&serv_address, sizeof(serv_address));

    serv_address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &serv_address.sin_addr);
    serv_address.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("socket error\n");
        return -1;
    }

    struct timeval timeout;
    timeout.tv_sec = time;
    timeout.tv_usec = 0;

    socklen_t len = sizeof(timeout);

    int ret = setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, len);
    if(ret < 0){
        printf("setsockopt error\n");
        close(sockfd);
        return -1;
    }

    ret = connect(sockfd, (struct sockaddr*)&serv_address, sizeof(serv_address));
    if(ret == -1){
        if(errno == EINPROGRESS){
            printf("connecting timeout\n");
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
        printf("input: %s ip_address port_number\n", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[1]);


    int sockfd = timeout_connect(ip, port, 10);
    if(sockfd < 0){
        printf("timeout_connect error\n");
        return -1;
    }

    return 0;
}
