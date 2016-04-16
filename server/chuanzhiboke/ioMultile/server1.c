/*************************************************************************
	> File Name: server1.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月16日 星期六 11时28分03秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char * argv[])
{
    if(argc < 3){
        printf("input: %s ip_address port_num\n", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    //socket创建socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("socket error\n");
        return -1;
    }

    struct sockaddr_in seraddr;
    bzero(&seraddr, sizeof(seraddr));

    seraddr.sin_port = htons(port);
    seraddr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &seraddr.sin_addr);

    //bind端口和ip地址
    int ret = bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    if(ret < 0){
        printf("bind error\n");
        return -1;
    }

    //listen
    ret = listen(sockfd, 5);
    if(ret < 0){
        printf("listen error\n");
        return -1;
    }

    //accept
    struct sockaddr_in client_addr;
    socklen_t client_len;

    int connfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if(connfd < 0){
        printf("accept error\n");
        return -1;
    }

    printf("accept a client.\n");
    char buff[1024];
    while(1){
        memset(buff, 0, 1024);

        int num = read(connfd, buff, 1024);
        if(num == 0){
            printf("client exit....\n");
            break;
        }
        else{
            printf("server: %s\n", buff);
            write(connfd, buff, strlen(buff));
        }

    }

    close(sockfd);
    close(connfd);



    return 0;
}
