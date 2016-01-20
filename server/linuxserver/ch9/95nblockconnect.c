/*************************************************************************
	> File Name: 95nblockconnect.c
	> Author: 
	> Mail: 
	> Created Time: 2016年01月20日 星期三 10时25分45秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1023

int setnonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFD);
    int new_option = old_option | O_NONBLOCK;
    
    fcntl(fd, F_SETFD, new_option);
    return old_option;

}

int unblock_connect(const char * ip, int port, int time)
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

    int fd_oldopt = setnonblocking(sockfd);

    ret = connect(sockfd, (struct sockaddr *)&address, sizeof(address));
    if(ret == 0){
        printf("connect with server immediately\n");
        fcntl(sockfd, F_SETFD, fd_oldopt);
        return sockfd;
    }
    else if(errno != EINPROGRESS){
        printf("unblock not support\n");
        return -1;
    }

    fd_set readfds;
    fd_set writefds;
    struct timeval timeout;
    FD_ZERO(&readfds);
    FD_ZERO(&writefds);
    FD_SET(sockfd, &writefds);

    timeout.tv_sec = time;
    timeout.tv_usec = 0;

    ret = select(sockfd + 1, NULL, &writefds, NULL, &timeout);
    if(ret <= 0){
        printf("connection time out\n");
        close(sockfd);
        return -1;
    }

    if(!FD_ISSET(sockfd, &writefds)){
        printf("no events on sockfd found\n");
        close(sockfd);
        return -1;
    }


}


int main(int argc, char ** argv)
{
    if(argc <= 2){
        printf("%s ip_address port_num\n", argv[0]);
        return -1;
    } 

    const char * ip = argv[1];
    int port = atoi(argv[2]);
    int sockfd = unblock_connect(ip, port, 10);
    if(sockfd < 0){
        return -1;
    }

    close(sockfd);

    return 0;
}
