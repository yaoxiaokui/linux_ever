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
    char sendbuff[MAXNUM];

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
    
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0){
        perror("setsockopt bind\n");
        exit(0);
    }

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
    memset(sendbuff, 0, MAXNUM);

    pid_t pid = fork();
    if(pid < 0){
        perror("fork error\n");
        exit(0);
    }
    else if(pid == 0){
        int recv_cnt = 0;
        while(1){
            recv_cnt = read(connfd, recvbuff, MAXNUM);
            if(recv_cnt == -1){
                perror("read error\n");
                break;
            }

            if(recv_cnt == 0){
                perror("perr closed\n");
                break;
            }
            printf("from %s:%d --- ", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
            fputs(recvbuff, stdout);
            memset(recvbuff, 0, MAXNUM);
        }

    }
    else if(pid > 0){
        while(fgets(sendbuff, MAXNUM, stdin) != NULL){

            if(write(connfd, sendbuff, strlen(sendbuff)) < 0){
                perror("write error\n");
                exit(0);
            }        
            memset(sendbuff, 0, MAXNUM);
        }
    }

    close(connfd);
    close(sockfd);

    exit(0);
}
