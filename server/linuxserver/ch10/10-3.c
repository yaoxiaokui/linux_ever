/*************************************************************************
	> File Name: 10-3.c
	> Author: 
	> Mail: 
	> Created Time: 2016年01月21日 星期四 20时21分10秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

static int connfd;
#define BUFF_SIZE 1024

void sig_urg(int sig)
{
    int save_error = errno;
    char buffer[BUFF_SIZE];
    memset(buffer, 0, BUFF_SIZE);
    int ret = recv(connfd, buffer, BUFF_SIZE-1, MSG_OOB);
    if(ret > 0){
        printf("get %d bytes of oob data: %s\n", ret, buffer);
    }
    errno = save_error;
}


void addsig(int sig, void (*sig_handler)(int))
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sig_handler;
    sa.sa_flags |= SA_RESTART;
    sigfillset(&sa.sa_mask);
    sigaction(sig, &sa, NULL);
}

int main(int argc, char *argv[])
{
    if(argc <= 2){
        printf("%s ip_address port_num\n", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));

    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd <= 0){
        printf("socket error\n");
        return -1;
    }

    int ret = bind(sockfd, (struct sockaddr *)&address, sizeof(address));
    if(ret < 0){
        printf("bind error\n");
        return -1;
    }

    ret = listen(sockfd, 5);
    if(ret < 0){
        printf("listen error\n");
        return -1;
    }

    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    connfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if(connfd < 0){
        printf("accept error, error is %d\n", errno);
        return -1;
    }
    else{
        addsig(SIGURG, sig_urg);
        fcntl(connfd, F_SETOWN, getpid());
        char buffer[BUFF_SIZE];
        while(1){
            memset(buffer, 0, BUFF_SIZE);
            ret = recv(connfd, buffer, BUFF_SIZE, 0);
            if(ret < 0){
                break;
            }
            else if(ret == 0){
                printf("client closed the conncetion\n");
                break;
            }
            else{
                printf("get %d bytes of normal data: %s\n", ret, buffer);
            }
        }
        close(connfd);
    }

    close(sockfd); 

    return 0;
}
