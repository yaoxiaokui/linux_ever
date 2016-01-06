/*************************************************************************
	> File Name: p2pser1.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月26日 星期四 19时52分35秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

const int MAXBUFFSIZE = 1024;

int main()
{
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("socket error\n");
        exit(-1);
    }

    struct sockaddr_in seraddr;
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(8001);
    //seraddr.sin_addr.s_addr = inet_addr(INADDR_ANY);
    seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    

    if(bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr)) != 0){
        perror("connect error\n");
        exit(-1);
    }
    
    if(listen(sockfd, SOMAXCONN) != 0){
        perror("listen error\n");
        exit(-1);
    }

    struct sockaddr_in cliaddr;
    socklen_t cliaddr_len;
    int connfd;
    printf("next is accept\n");
    connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
    if(connfd < 0){
        perror("accept error\n");
        exit(-1);
    }
     
    //parent read data from the connfd and output the data to the stdout;
    //child get data from the stdin and write the data to the connfd;
    pid_t pid = fork();
    if(pid < 0){
        perror("fork error\n");
        exit(-1);
    }

    if(pid > 0){//parent

        char recvbuff[MAXBUFFSIZE];
        memset(recvbuff, 0, MAXBUFFSIZE);
        int read_cnt = 0;
        while(1){
            read_cnt = read(connfd, recvbuff, MAXBUFFSIZE);
            if(read_cnt == -1){
                perror("read error\n");
                break;
            }
            else if(read_cnt == 0){
                printf("perror close\n");
                break;
            }
            fputs(recvbuff, stdin);
            memset(recvbuff, 0, MAXBUFFSIZE);
        }
    }
    else if(pid == 0){//child
        char sendbuff[MAXBUFFSIZE];
        memset(sendbuff, 0, MAXBUFFSIZE);
        while(fgets(sendbuff, MAXBUFFSIZE, stdin) != NULL){
            write(connfd, sendbuff, MAXBUFFSIZE);
            memset(sendbuff, 0, MAXBUFFSIZE);
        }
    }
    close(connfd);
    close(sockfd);
    exit(0);
}
