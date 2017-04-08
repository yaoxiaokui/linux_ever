/*************************************************************************
	> File Name: oobMsgClient.c
	> Author: 
	> Mail: 
	> Created Time: Thu 26 May 2016 06:05:19 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>



//服务器，接收数据
int main(int argc, char * argv[])
{
    if(argc < 4){
        printf("input: %s, ip, port, recvive buffer lenght\n", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);
    int recvBufLen = atoi(argv[3]);

    //创建sockfd
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("socket error\n");
        return -1;
    }

    int recvLen = 0;
    int len = sizeof(recvLen);
    getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &recvLen, (socklen_t*)&len);
    printf("默认的接收缓冲区大小为: %d\n", recvLen);

    //int len = sizeof(recvLen);
    setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &recvBufLen, len);

    getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &recvLen, (socklen_t*)&len);
    printf("设置之后的接收缓冲区大小为: %d\n", recvLen);


    //连接服务器listen sockfd
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    int ret = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
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

    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    socklen_t client_addr_len;
    int connfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_addr_len);
    if(connfd < 0){
        printf("accept error\n");
        return -1;
    }

    char buffer[1024];
    memset(buffer, 0, 1024);

    recv(connfd, buffer, sizeof(buffer), 0);
    printf("1: %s\n", buffer);
    
    memset(buffer, 0, 1024);
    recv(connfd, buffer, sizeof(buffer), MSG_OOB);
    printf("2: %s\n", buffer);

    memset(buffer, 0, 1024);
    recv(connfd, buffer, sizeof(buffer), 0);
    printf("3: %s\n", buffer);


    return 0;
}
