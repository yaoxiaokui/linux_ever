/*************************************************************************
	> File Name: dupServer.c
	> Author: 
	> Mail: 
	> Created Time: Fri 27 May 2016 03:54:12 PM CST
 ************************************************************************/

#include <stdio.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//客户端，用来测试CGI服务器
int main(int argc, char *argv[])
{

    if(argc < 3){
        printf("input: %s, ip, port\n", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    //创建sockfd
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket < 0){
        printf("socket error\n");
        return -1;
    }

    //绑定地址
    struct sockaddr_in seraddr;
    memset(&seraddr, 0, sizeof(seraddr));

    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &seraddr.sin_addr);

    int ret = connect(sockfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
    if(ret < 0){
        printf("connect error\n");
        return -1;
    }
    else{
        char buffer[1024];
        memset(buffer, 0, 1024);

        read(sockfd, buffer, 1024);
        printf("read: %s\n", buffer);
        //sleep(10);
    }


    return 0;
}
