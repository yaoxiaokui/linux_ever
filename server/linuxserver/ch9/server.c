/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: 2016年01月20日 星期三 11时24分11秒
 ************************************************************************/

#define _GNU_SOURCE 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <errno.h>

#define USER_LIMIT 5  //max user number
#define BUFFER_SIZE 100 //max size of read buffer
#define FD_LIMIT 65535  //max number of file operators

struct client_data
{
    struct sockaddr_in address;
    char * write_buf;
    char buf[BUFFER_SIZE];
};

int setnonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFD);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFD, new_option);

    return old_option;
}


int main(int argc, char *argv[])
{
    if(argc <= 2){
        printf("Please input: %s ip_address port_num\n", argv[0]);
        return -1;
    }

    /*************************************/

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));

    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);

    /*************************************/

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
    
    /*************************************/

    struct client_data * users = malloc(sizeof(struct client_data)*FD_LIMIT);//new client_data[FD_LIMIT];
    int user_counter = 0;

    struct pollfd pollfds[USER_LIMIT+1];

    int i = 0;
    for(i = 1; i <= USER_LIMIT; ++i){
        pollfds[i].fd = -1;
        pollfds[i].events = 0;
    }

    pollfds[0].fd = 0;
    pollfds[0].events = POLLIN | POLLERR;
    pollfds[0].revents = 0;

    while(1){
        ret = poll(pollfds, user_counter+1, -1);
        if(ret < 0){
            printf("poll error\n");
            break;
        }

        for(i = 0; i < user_counter+1; ++i){
            if((pollfds[i].fd == sockfd) && (pollfds[i].events & POLLIN)){  //new connection 
                struct sockaddr_in client_addr;
                socklen_t client_addr_len;
                int connfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_addr_len);
                if(connfd < 0){
                    printf("accept error = %d\n", errno);
                    continue;
                }

                if(user_counter >= USER_LIMIT){
                    const char * info = "too many users\n";
                    printf("%s", info);
                    send(connfd, info, strlen(info), 0);
                    close(connfd);
                    continue;
                }
                
                user_counter++;
                users[connfd].address = client_addr;
                setnonblocking(connfd);
                pollfds[user_counter].fd = connfd;
                pollfds[user_counter].events = POLLIN | POLLRDHUP | POLLERR;
                pollfds[user_counter].revents = 0;

                printf("come a new user, new we have %d users.\n", user_counter);
            }
            else if(pollfds[i].revents & POLLERR){
                printf("get an error from %d\n", pollfds[i].fd);
                char errors[100];
                memset(errors, 0, 100);
                socklen_t length = sizeof(errors);
                if(getsockopt(pollfds[i].fd, SOL_SOCKET, SO_ERROR, &errors, &length) < 0){
                    printf("get socket option error\n");
                }
                continue;
            }
            else if(pollfds[i].revents & POLLRDHUP){
                //client close the conncetion
                users[pollfds[i].fd] = users[pollfds[user_counter].fd];
                close(pollfds[i].fd);
                pollfds[i] = pollfds[user_counter];
                i--;
                user_counter--;
                printf("a client left\n");
            }
            else if(pollfds[i].revents & POLLIN){
                int connfd = pollfds[i].fd;
                memset(users[connfd].buf, 0, BUFFER_SIZE);
                ret = recv(connfd, users[connfd].buf, BUFFER_SIZE-1, 0);
                printf("get %d bytes of client data %s from %d\n", ret, users[connfd].buf, connfd);
                if(ret < 0){
                    if(errno != EAGAIN){
                        close(connfd);
                        users[pollfds[i].fd] = users[pollfds[user_counter].fd];
                        pollfds[i] = pollfds[user_counter];
                        i--;
                        user_counter--;
                    }
                }
                else if(ret == 0){
                    
                }
                else{
                    //recvive the data
                    int j;
                    for(j = 1; j <= user_counter; ++j){
                        if(pollfds[j].fd == connfd){
                            continue;
                        }
                        pollfds[j].events |= ~POLLIN;
                        pollfds[j].events |= POLLOUT;
                        users[pollfds[j].fd].write_buf = users[connfd].buf;
                    }
                }
            }
            else if(pollfds[i].revents & POLLOUT){
                int connfd = pollfds[i].fd;
                if(!users[connfd].write_buf){
                    continue;
                }
                ret = send(connfd, users[connfd].write_buf, strlen(users[connfd].write_buf), 0);
                users[connfd].write_buf = NULL;

                pollfds[i].events |= ~POLLOUT;
                pollfds[i].events |= POLLIN;
            }
        }
    }

    free(users);
    close(sockfd);

    return 0;
}
