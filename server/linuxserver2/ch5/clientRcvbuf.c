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
    if(argc < 4){
        printf("input: %s, ip, port, send buffer lenght\n", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);
    int sndBuffLen = atoi(argv[3]);

    //创建sockfd
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("socket error\n");
        return -1;
    }

    int sndLen = 0;
    int len = sizeof(sndLen);
    getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &sndLen, (socklen_t*)&len);
    printf("默认的发送缓冲区大小为: %d\n", sndLen);

    //int len = sizeof(recvLen);
    setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &sndBuffLen, len);

    getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &sndBuffLen, (socklen_t*)&len);
    printf("设置之后的发送缓冲区大小为: %d\n", sndLen);

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
        const char * normal = "normal data";
        const char * oob = "oob data!";

        send(sockfd, normal, strlen(normal), 0);
        send(sockfd, oob, strlen(oob), MSG_OOB);
        send(sockfd, normal, strlen(normal), 0);
    }



    return 0;
}
