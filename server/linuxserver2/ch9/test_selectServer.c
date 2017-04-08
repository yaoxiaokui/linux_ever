/*************************************************************************
	> File Name: test_select.c
	> Author: 
	> Mail: 
	> Created Time: Wed 01 Jun 2016 08:44:51 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>

int main(int argc, char * argv[])
{
    if(argc < 3){
        printf("input: %s ip port\n", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    //create sockfd
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("socket error\n");
        return -1;
    }

    struct sockaddr_in serveraddr;
    bzero(&serveraddr, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &serveraddr.sin_addr);
    serveraddr.sin_port = htons(port);
    //绑定
    int ret = bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    if(ret != 0){
        printf("bind error\n");
        close(sockfd);
        return -1;
    }

    //listen
    ret = listen(sockfd, 5);

    struct sockaddr_in clientaddr;
    bzero(&clientaddr, sizeof(clientaddr));
    socklen_t clientaddrlen;
    //
    while(1){

        int connfd = accept(sockfd, (struct sockaddr *)&clientaddr, &clientaddrlen);
        if(connfd < 0){
            printf("accept error\n");
            continue;
        }

        printf("-----------------------------------------------\n");
        printf("new connection.\n");

        
        fd_set readfds;
        fd_set exceptfds;
        FD_ZERO(&readfds);
        FD_ZERO(&exceptfds);

        int num = 0;
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));

        //循环读取直到全部读完
        while(1){
            memset(buffer, 0, sizeof(buffer));
            FD_SET(connfd, &readfds);
            FD_SET(connfd, &exceptfds);

            ret = select(connfd + 1, &readfds, NULL, &exceptfds, NULL);
            if(ret < 0){
                printf("select error\n");
                close(connfd);
                continue;
            }

            if(FD_ISSET(connfd, &readfds)){//可读
                int num = recv(connfd, buffer, sizeof(buffer), 0);
                if(num <= 0)
                    break;
                printf("receive: %s\n", buffer);
                /*
                while((num  = recv(connfd, buffer, sizeof(buffer), 0)) != 0){
                    printf("receive: %s\n", buffer);
                    memset(buffer, 0, sizeof(buffer));
                }
                break;
                */
            }
            else if(FD_ISSET(connfd, &exceptfds)){//异常
                int num = recv(connfd, buffer, sizeof(buffer), MSG_OOB);
                if(num <= 0)
                    break;
                printf("receive oob: %s\n", buffer);
                /*
                while((num  = recv(connfd, buffer, sizeof(buffer), MSG_OOB)) != 0){
                    printf("receive oob: %s\n", buffer);
                    memset(buffer, 0, sizeof(buffer));
                }
                break;
                */
            }
            
        }
        printf("receive over!\n");

        close(connfd);


    }
    close(sockfd);

    return 0;
}
