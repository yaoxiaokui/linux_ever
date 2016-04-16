/*************************************************************************
	> File Name: server1.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月16日 星期六 11时28分03秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char * argv[])
{
    if(argc < 3){
        printf("input: %s ip_address port_num\n", argv[0]);
        return -1;
    }

    int port = atoi(argv[2]);
    const char * ip = argv[1];

    //socket创建socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("socket error\n");
        return -1;
    }

    struct sockaddr_in seraddr;
    bzero(&seraddr, sizeof(seraddr));
    seraddr.sin_port = htons(port);
    seraddr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &seraddr.sin_addr);


    int ret = connect(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    if(ret < 0){
        printf("connect error\n");
        return -1;
    }

    char buff[1024];
    //for(ret = 0; ret < 10; ++ret){
    while(1){
        memset(buff, 0, 1024);

        fgets(buff, 1024, stdin);        
        //printf("%d\n", strlen(buff));
        write(sockfd, buff, strlen(buff)-1);

        int num = read(sockfd, buff, 1024);
        if(num == 0){
            printf("client exit....\n");
            break;
        }
        else{
            printf("server: %s", buff);
        }

    }

    close(sockfd);

    return 0;
}
