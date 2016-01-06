/*************************************************************************
	> File Name: ser01.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月22日 星期日 10时22分17秒
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

int main()
{
   //int socket(int domain, int type, int protocol);
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in seraddr;
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(8001);
    seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));

    listen(sockfd, 128);


    struct sockaddr_in cliaddr;
    socklen_t clilen;
    
    int connfd;
    char recvbuf[2014] = {0};
    int recvcount = 0;

    while(1){
        connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        if(connfd == -1){
            perror("accept error.\n");
            exit(EXIT_FAILURE);
        }
        pid_t pid = fork();
    
        if(pid == 0){
            while(1){
                recvcount = read(connfd, recvbuf,1024); 
                if (recvcount == 0){
                    printf("%s:%d is over.\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
                    exit(0);
                }
                else if (recvcount == -1){
                    perror("read error.\n");
                    exit(EXIT_FAILURE);
                }
                printf("%d receive from %s:%d - ", getpid(), inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
                fputs(recvbuf, stdout);
                write(connfd, recvbuf, strlen(recvbuf));
                memset(recvbuf, 0, 1024);
            }
        }
        else if(pid > 0){

        }
        else if(pid < 0){
            perror("fork error.\n");
            exit(EXIT_FAILURE);
        }
    }

    exit(0);
}
