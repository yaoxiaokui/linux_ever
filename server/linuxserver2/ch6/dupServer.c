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

//CGI服务器，将标准输出文件描述符复制到连接socket上
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

    int ret = bind(sockfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
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
    socklen_t len = sizeof(client_addr);

    int connfd = accept(sockfd, (struct sockaddr*)&client_addr, &len);
    if(connfd < 0){
        printf("accept error\n");
        return -1;
    }
    else{
        close(1);
        int newconnfd = dup(connfd);

        printf("I am a server!");
        //sleep(10);
    }


    return 0;
}
