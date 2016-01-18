/*************************************************************************
	> File Name: 61dup.c
	> Author: 
	> Mail: 
	> Created Time: 2016年01月16日 星期六 22时23分35秒
 ************************************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc <= 2){
        printf("usage: %s ip_address port_number\n", argv[0]);
        return 1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, ip, &address.sin_addr);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("socket failed\n");
        return -1;
    }

    int ret = bind(sockfd, (struct sockaddr *)&address, sizeof(address));
    assert(ret != -1);

    ret = listen(sockfd, 5);
    assert(ret != -1);

    struct sockaddr_in clientaddr;
    socklen_t clientaddr_len;

    int connfd = accept(sockfd, (struct sockaddr *)&clientaddr, &clientaddr_len);
    if(connfd < 0){
        printf("connect error\n");
    }
    else{
        close(STDOUT_FILENO);
        dup(connfd);
        printf("abcd");
        close(connfd);
    }
    close(sockfd);

    return 0;
}
