/*************************************************************************
	> File Name: poll_client.c
	> Author: 
	> Mail: 
	> Created Time: 2016年02月26日 星期五 20时25分24秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>


int handle_connection(int sockfd)
{
    char sendbuf[1024], recvbuf[1024];
    struct pollfd pfds[2];
    int num;
    //添加连接套接字
    pfds[0].fd = sockfd;
    pfds[0].events = POLLIN;
    //添加标准输入文件描述符
    pfds[1].fd = STDIN_FILENO;
    pfds[1].events = POLLIN;

    for(; ;){
        poll(pfds, 2, -1);
        //连接文件描述符准备好
        if(pfds[0].revents & POLLIN){
            num = read(sockfd, recvbuf, 1024);
            if(num == 0){
                printf("client: server closed.\n");
                close(sockfd);
            }
            //将收到的内容输出到标准输出
            write(STDOUT_FILENO, recvbuf, num);
        }
        //测试标准输入是否就绪
        if(pfds[1].revents & POLLIN){
            num = read(STDIN_FILENO, sendbuf, 1024);
            if(num == 0){
                continue;
            }
            write(sockfd, sendbuf, num);
        }
    }
    return 0;
}


int main(int argc, char *argv[])
{
    if(argc <= 2){
        printf("input the: %s ipaddr port", argv[0]);
        return -1;
    }
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &servaddr.sin_addr);
    servaddr.sin_port = htons(port);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    
    //处理连接套接字
    handle_connection(sockfd);

    return 0;
}
