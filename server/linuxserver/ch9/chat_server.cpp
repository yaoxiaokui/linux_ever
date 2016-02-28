/*************************************************************************
	> File Name: chat_client.c
	> Author: 
	> Mail: 
	> Created Time: 2016年02月28日 星期日 14时19分47秒
 ************************************************************************/

/*
接收客户数据，并把每个客户数据发送给每一个登录到该服务器上的客户端（发送者除外）
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
#include <errno.h>

#define BUFFER_SIZE 1024
#define USER_LIMIT 20//最大客户数目
#define FD_LIIMIT 65535//最大文件描述符数量

/*客户数据：客户端socket地址，待写入到客户端的数据的位置，从客户端读入的数据*/
struct client_data{
    struct sockaddr_in address;
    char * write_buf;
    char buf[BUFFER_SIZE];
};

int setnonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}


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

    int ret = bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
    if(ret < 0){
        printf("bind error\n");
        close(sockfd);
        return -1;
    }

    ret = listen(sockfd, 5);
    if(ret < 0){
        printf("listen error\n");
        close(sockfd);
        return -1;
    }

    //分配client_data对象
    struct client_data *users = new client_data[FD_LIIMIT];


    struct pollfd fds[USER_LIMIT+1];
    int user_counter = 0;
    for(int i = 1; i <= USER_LIMIT; ++i){
        fds[i].fd = -1;
        fds[i].events = 0;
    }

//注册监听套接字上的可读事件
    fds[0].fd = sockfd;
    fds[0].events = POLLIN | POLLERR;
    fds[0].revents = 0;

    //循环
    while(1){
        ret = poll(fds, user_counter+1, -1);
        if(ret < 0){
            printf("polll error\n");
            break;
        }

        //遍历所有事件
        for(int i = 0; i < user_counter+1; ++i){
            //新的连接
            if((fds[i].fd == sockfd)&&(fds[i].revents & POLLIN)){
                struct sockaddr_in client_address;
                socklen_t client_addresslen = sizeof(client_address);
                int connfd = accept(sockfd, (struct sockaddr*)&client_address, &client_addresslen);
                if(connfd < 0){
                    printf("accept error\n");
                    continue;
                }
                //如果连接个数等于最大的数
                if(user_counter >= USER_LIMIT){
                    const char * info = "too many users\n";
                    printf("%s", info);
                    send(connfd, info, strlen(info), 0);
                }
                //新的连接
                user_counter++;
                users[connfd].address = client_address;
                setnonblocking(connfd);
                fds[user_counter].fd = connfd;
                fds[user_counter].events = POLLIN | POLLRDHUP | POLLERR;
                fds[user_counter].revents = 0;
                printf("a new user, now have %d users\n", user_counter);
            }
            else if(fds[i].revents & POLLERR){//表明出错了
                printf("get an error from %d\n", fds[i].fd);
                char errors[100];
                memset(errors, 0, 100);
                socklen_t length = sizeof(errors);
                if(getsockopt(fds[i].fd, SOL_SOCKET, SO_ERROR, &errors, &length) < 0){
                     printf("getsockopt error\n");                             
                }
                continue;
            }
            else if(fds[i].revents & POLLRDHUP){//对端关闭
                users[fds[i].fd] = users[fds[user_counter].fd];
                close(fds[i].fd);
                fds[i] = fds[user_counter];
                i--;
                user_counter--;
                printf("a client left\n");
            }
            else if(fds[i].revents & POLLIN){//连接套接字可读
                int connfd = fds[i].fd;
                memset(users[connfd].buf, 0, BUFFER_SIZE);
                ret = recv(connfd, users[connfd].buf, BUFFER_SIZE-1, 0);
                printf("get %d bytes of client data from %d: %s\n", ret, connfd, users[connfd].buf);
                if(ret < 0){
                    if(errno != EAGAIN){
                        close(connfd);
                        users[fds[i].fd] = users[fds[user_counter].fd];
                        fds[i] = fds[user_counter];
                        i--;
                        user_counter--;
                    }
                }
                if(ret == 0){
                }
                else{//有数据,将数据发送给其它客户端
                    for(int j = 1; j <= user_counter; ++j)
                    {
                        if(fds[j].fd == connfd)
                        {
                            continue;//不向发送数据的客户端发送数据
                        }
                        fds[j].events |= ~POLLIN;
                        fds[j].events |= POLLOUT;
                        users[fds[j].fd].write_buf = users[connfd].buf;
                    }
                }
            }
            else if(fds[i].revents & POLLOUT){
                //套接字可写
                int connfd = fds[i].fd;
                if(!users[connfd].write_buf){
                    continue;
                }
                printf("server send: %s\n", users[connfd].write_buf);

                ret = send(connfd, users[connfd].write_buf, strlen(users[connfd].write_buf), 0);
                users[connfd].write_buf = NULL;
                //写完数据后重新注册可读事件
                fds[i].events |= ~POLLOUT;
                fds[i].events |= POLLIN;
            }
        }
    }

    delete [] users;

    close(sockfd);

    return 0;
}


