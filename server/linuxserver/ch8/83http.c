/*************************************************************************
	> File Name: 83http.c
	> Author: 
	> Mail: 
	> Created Time: 2016年01月18日 星期一 22时00分12秒
 ************************************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

enum CHECK_STATE{CHECK_STATE_REQUESTLINE=0, CHECK_STATE_HEADER};

enum LINE_STATE{LINE_OK = 0, LINE_BAD, LINE_OPEN};
enum HTTP_CODE{NO_REQUEST, GET_REQUEST, BAD_REQUEST, FORBIDDEN_REQUEST, INTERNAL_ERROR, CLOSED_CONNECTION};

static const char * szret = {"I get a correct result\n", "Something wrong\n"};





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

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, ip, (void *)&address.sin_addr);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("socket failed\n");
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
    if(connfd < 0){
        printf("accept error\n");
        return -1;
    }
    else{
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
        int data_read = 0;
        int read_index = 0;
        int checked_index = 0;
        int start_line = 0;

        CHECK_STATE checkstate = CHECK_STATE_REQUESTLINE;
        while(1){
            data_read = recv(connfd, buffer+read_index, BUFFER_SIZE-read_index, 0);
            if(data_read == -1){
                printf("reading failed\n");
                break;
            }
            else if(data_read == 0){
                printf("remote client has closed the connection\n");
                break;
            }

            read_index += data_read;

            HTTP_CODE result = parse_content(buffer, checked_index, checkstate, read_index, start_line);
            if(result == NO_REQUEST){
                continue;
            }
            else if(result == GET_REQUEST){
                send(connfd, szret[0], strlen(szret[0]), 0);
                break;
            }
            else{
                send(connfd, szret[1], strlen(szret[1]), 0);
                break;
            }
        }
        close(connfd);
    }    
    
    close(sockfd);

    return 0;
}

