/*************************************************************************
	> File Name: p2pcli1.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月26日 星期四 19时25分35秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
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

    printf("next is connect\n");
    if(connect(sockfd, (struct sockaddr*)&seraddr, sizeof(seraddr)) != 0){
        perror("connect error\n");
        exit(-1);
    }

    //parents get data from the stdin and write the data to sockfd;
    //child read the data from the socket and output the data to the stdout;
    
    pid_t pid = fork();
    
    if(pid < 0){
        perror("fork error\n");
        exit(-1);
    }
    else if(pid > 0){//parent
        char sendbuff[MAXBUFFSIZE];
        memset(sendbuff, 0, MAXBUFFSIZE);

        while(fgets(sendbuff, MAXBUFFSIZE, stdin) != NULL){
            write(sockfd, sendbuff, strlen(sendbuff));
            memset(sendbuff, 0, MAXBUFFSIZE);
        }
    }
    else if(pid == 0){//child
        char recvbuff[MAXBUFFSIZE];
        memset(recvbuff, 0, MAXBUFFSIZE);
        int read_cnt = 0;

        while(1){
            read_cnt = read(sockfd, recvbuff, MAXBUFFSIZE);
            if(read_cnt == -1){
                perror("read error\n");
                break;
            }
            else if(read_cnt == 0){
                printf("read over\n");
                break;
            }
            fputs(recvbuff, stdout);
            memset(recvbuff, 0, MAXBUFFSIZE);
        }
    }

    exit(0);
}
