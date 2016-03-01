/*************************************************************************
	> File Name: chat_client.c
	> Author: 
	> Mail: 
	> Created Time: 2016年02月28日 星期日 14时19分47秒
 ************************************************************************/

/*
1:从标准输入终端读入用户数据，并将数据发送到服务器
2:向标准输入终端打印服务器发送给它的数据
*/


#define _GNU_SOURCE 1

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <poll.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if(argc <= 2){
        printf("input: %s ip_address port_num", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);
    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &server_address.sin_addr);
    server_address.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("socket error\n");
        return -1;
    }

    int ret = connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
    if(ret < 0){
        printf("connect error\n");
        close(sockfd);
        return -1;
    }

    struct pollfd fds[2];
    //注册文件描述符0和sockfd上的可读事件
    fds[0].fd = 0;
    fds[0].events = POLLIN;
    fds[0].revents = 0;

    fds[1].fd = sockfd;
    fds[1].events = POLLIN | POLLRDHUP;
    fds[1].revents = 0;

    char read_buf[BUFFER_SIZE];
    int pipefd[2];
    ret = pipe(pipefd);
    if(ret < 0){
        printf("pipe error\n");
        return -1;
    }

    //循环
    while(1){
        ret = poll(fds, 2, -1);
        if(ret < 0){
            printf("polll error\n");
            break;
        }

        //标准输入有数据可读
        if(fds[0].revents & POLLIN){
            //0---->pipefd[1]
            ret = splice(0, NULL, pipefd[1], NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE); 

            //pipefd[0]--->sockfd
            ret = splice(pipefd[0], NULL, sockfd, NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE); 
        }

        //先判断对端是否关闭了连接
        if(fds[1].revents & POLLRDHUP){
            printf("服务器关闭了\n");
            break;
        }
        else if(fds[1].revents & POLLIN){
            memset(read_buf, 0, BUFFER_SIZE);

            ret = recv(fds[1].fd, read_buf, BUFFER_SIZE-1, 0);
            printf("from server: ");
            ret = send(0, read_buf, ret, 0);
        }
    }

    close(sockfd);

    return 0;
}


