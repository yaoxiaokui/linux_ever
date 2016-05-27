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



//客户端，发送数据
int main(int argc, char * argv[])
{
    if(argc < 3){
        printf("input: %s, ip, port\n", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    //创建sockfd
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("socket error\n");
        return -1;
    }

    //连接服务器listen sockfd
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    int ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if(ret < 0){
        printf("connect error\n");
        return -1;
    }
    else{
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        socklen_t len;

        char buff[1024];
        memset(buff, 0, 1024);

        getsockname(sockfd, (struct sockaddr*)&addr, &len);
        printf("自身的socket地址: %s: %d\n", inet_ntop(AF_INET, &addr.sin_addr, buff, sizeof(addr)), ntohs(addr.sin_port));

        struct sockaddr_in peerAddr;
        socklen_t len2;

        memset(buff, 0, 1024);
        memset(&peerAddr, 0, sizeof(peerAddr));

        //getpeername(sockfd, (struct sockaddr*)&peerAddr, &len2);
        //printf("对端的socket地址: %s: %d\n", inet_ntop(AF_INET, &peerAddr.sin_addr, buff, sizeof(peerAddr)), ntohs(peerAddr.sin_port));
    
    }



    return 0;
}
