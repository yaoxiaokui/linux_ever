/*************************************************************************
	> File Name: practice_91.c
	> Author: 
	> Mail: 
	> Created Time: 2016年02月24日 星期三 15时38分01秒
 ************************************************************************/
/*
能够同时接收普通数据和带外数据
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>


int main(int argc, char *argv[])
{
    if(argc <= 2){
        printf("%s ip_address port_number\n", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    int ret = 0;

    struct sockaddr_in address;
    bzero(&address, sizeof(address));

    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);
    
    //socket
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0){
        printf("socket error\n");
        return -1;
    }

    //bind
    ret = bind(listenfd, (struct sockaddr *)&address, sizeof(address));
    if(ret != 0){
        printf("bind error\n");
        return -1;
    }

    //listen
    ret = listen(listenfd, 5);
    if(ret != 0){
        printf("listen error\n");
        return -1;
    }

    //客户端地址
    struct sockaddr_in client_addr;
    socklen_t client_addrlen = sizeof(client_addr);
    
    //accept
    int connfd = accept(listenfd, (struct sockaddr *)&client_addr, &client_addrlen);
    if(connfd < 0){
        printf("accept error\n");
        close(listenfd);
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
    
        ret = select(connfd+1, &read_fds, NULL, &exception_fds, NULL);//会一直阻塞，直到文件描述符就绪
        if(ret < 0){
            printf("select error\n");
            break;
        }

        if(FD_ISSET(connfd, &read_fds)){//正常可读事件
            ret = recv(connfd, buf, sizeof(buf)-1, 0);
            if(ret <= 0){//ret == 0表示对方关闭了连接
                break;
            }
            printf("get %d bytes of normal data: %s\n", ret, buf);
        }
        else if(FD_ISSET(connfd, &exception_fds)){//对于异常事件
            ret = recv(connfd, buf, sizeof(buf)-1, MSG_OOB);
            if(ret <= 0){//ret == 0表示对方关闭了连接
                break;
            }
            printf("get %d bytes of oob data: %s\n", ret, buf);
        }
    }
    
    close(connfd);
    close(listenfd);

    return 0;
}
