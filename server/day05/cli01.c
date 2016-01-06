/*************************************************************************
	> File Name: cli01.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月22日 星期日 11时56分05秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>


int main()
{
    
    int sockfd, ret;
    struct sockaddr_in seraddr;
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(8001);
    seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    ret = connect(sockfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
    if(ret == -1){
        perror("bind error.\n");
        exit(EXIT_FAILURE);
    }
    
    char recvbuf[1024] = {0};
    char sendbuff[1024] = {0};

    while(fgets(sendbuff, 1024, stdin) != NULL){
        write(sockfd, sendbuff, strlen(sendbuff));
        read(sockfd, recvbuf, 1024);
        fputs(recvbuf, stdout);
        memset(recvbuf, 0, 1024);
        memset(sendbuff, 0, 1024);
    }
    
    exit(0);
}
