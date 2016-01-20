/*************************************************************************
	> File Name: 91.c
	> Author: 
	> Mail: 
	> Created Time: 2016年01月19日 星期二 10时14分18秒
 ************************************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc <= 2){
        printf("usage: %s ip_address port_num\n", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));

    address.sin_port = htons(port);
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd <= 0){
        printf("socket error\n");
        return -1;
    }

    int ret = bind(sockfd, (struct sockaddr *)&address, sizeof(address));
    if(ret != 0){
        printf("bind error\n");
        return -1;
    }

    ret = listen(sockfd, 5);
    if(ret != 0){
        printf("listen error\n");
        return -1;
    }

    struct sockaddr_in client_addr;
    socklen_t client_addr_len;

    int connfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if(connfd <= 0){
        printf("accept error\n");
        close(sockfd);
        return -1;
    }

    char buf[1024];
    fd_set read_fds;
    fd_set exception_fds;

    FD_ZERO(&read_fds);
    FD_ZERO(&exception_fds);

    while(1){
        memset(buf, 0, sizeof(buf));
        FD_SET(connfd, &read_fds);
        FD_SET(connfd, &exception_fds);

        ret = select(connfd+1, &read_fds, NULL, &exception_fds, NULL);//block function
        if(ret < 0){
            printf("select error\n");
            break;
        }

        if(FD_ISSET(connfd, &read_fds)){
            ret = recv(connfd, buf, sizeof(buf)-1, 0);
            if(ret <= 0){
                continue;    
              //  break;
            }

            printf("get %d bytes of normal data: %s\n", ret, buf);
        }
        else if(FD_ISSET(connfd, &exception_fds)){
            ret = recv(connfd, buf, sizeof(buf)-1, MSG_OOB);
            if(ret <= 0){
                continue;    
                //break;
            }

            printf("get %d bytes of oob data: %s\n", ret, buf);
        }

    }

    close(connfd);
    close(sockfd);

    return 0;
}
