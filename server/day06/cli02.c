/*************************************************************************
	> File Name: cli01.c
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

    if(connect(sockfd, (struct sockaddr*)&seraddr, sizeof(seraddr)) != 0){
        perror("connect error\n");
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
        int read_cnt = 0;
        while(1){
            read_cnt = read(sockfd, recvbuff, MAXNUM);
            if (read_cnt == -1){
                perror("read error\n");
                break;
            }
            else if (read_cnt == 0){
                perror("the peer closed\n");
                break;
            }    
            printf("from %s:%d --- ", inet_ntoa(seraddr.sin_addr), ntohs(seraddr.sin_port));
            fputs(recvbuff, stdout);
            memset(recvbuff, 0, MAXNUM);
        }
    }
    else if (pid > 0){
        while(fgets(sendbuff, MAXNUM, stdin) != NULL){
            if(write(sockfd, sendbuff, strlen(sendbuff)) < 0){
                perror("write error\n");
                exit(0);
            }        
            memset(sendbuff, 0, MAXNUM);
        }
    }

    close(sockfd);

    exit(0);
}
