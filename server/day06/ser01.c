/*************************************************************************
	> File Name: ser01.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月24日 星期二 20时20分11秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

const int MAXNUM = 1024;

int main()
{
   
    char recvbuff[MAXNUM];
    int sockfd;
    struct sockaddr_in seraddr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("socket error\n");
        exit(0);
    }
        
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(8001);
    seraddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //struct in_adrr.. unit32_t s_addr

    if(bind(sockfd, (struct sockaddr*)&seraddr, sizeof(seraddr)) != 0){
        perror("bind error\n");
        exit(0);
    }
    if(listen(sockfd, SOMAXCONN) != 0){
        perror("listen error\n");
        exit(0);
    }  
    struct sockaddr_in cliaddr;
    socklen_t clilen;

    int connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
    if(connfd < 0){
        perror("accept error\n");
        exit(0);
    }
    memset(recvbuff, 0, MAXNUM);

    while(1){
        if(read(connfd, recvbuff, MAXNUM) <= 0){
            //perror("read error\n");
            exit(0);
        }
        fputs(recvbuff, stdout);
        if(write(connfd, recvbuff, strlen(recvbuff)) < 0){
            //perror("write error\n");
            exit(0);
        }        
        memset(recvbuff, 0, MAXNUM);
    }

    close(sockfd);

    exit(0);
}
