/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: 2016年01月20日 星期三 10时55分53秒
 ************************************************************************/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <poll.h>
#include <fcntl.h>
#define BUFFER_SIZE 64

int main(int argc, char *argv[])
{
    if(argc <= 2){
        printf("Please input: %s ip_address port_num\n", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address,sizeof(address));

    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd <= 0){
        printf("socket error\n");
        return -1;
    }

    int ret = connect(sockfd, (struct sockaddr *)&address, sizeof(address));
    if(ret < 0){
        printf("connect error\n");
        close(sockfd);
        return -1;
    }

    struct pollfd pollfds[2];

    pollfds[0].fd = 0;
    pollfds[0].events = POLLIN;
    pollfds[0].revents = 0;

    pollfds[1].fd = sockfd;
    pollfds[1].events = POLLIN | POLLRDHUP;
    pollfds[1].revents = 0;

    char read_buffer[BUFFER_SIZE];

    int pipefd[2];
    ret = pipe(pipefd);
    if(ret < 0){
        printf("pipe error\n");
        return -1;
    }

    //listen the filefd of 0 and sockfd
    while(1){
        ret = poll(pollfds, 2, -1);
        if(ret < 0){
            printf("poll error\n");
            break;
        }

        if(pollfds[1].revents & POLLRDHUP){
            printf("server close the connection\n");
            break;
        }
        else if(pollfds[1].revents & POLLIN){
            memset(read_buffer, 0, BUFFER_SIZE);
            recv(pollfds[1].fd, read_buffer, BUFFER_SIZE-1, 0);
            printf("received: %s\n", read_buffer);
        }

        if(pollfds[0].revents & POLLIN){
            //0 ----> pipefd[1]
            ret = splice(0, NULL, pipefd[1], NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE);
            //pipefd[0] ----> sockfd
            ret = splice(pipefd[0], NULL, sockfd, NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE);
        }
    }

    close(sockfd);

    return 0;
}
