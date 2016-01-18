/*************************************************************************
	> File Name: 64splice.c
	> Author: 
	> Mail: 
	> Created Time: 2016年01月17日 星期日 20时13分08秒
 ************************************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define _GNU_SOURCE
#include <fcntl.h>

int main(int argc, char * argv[])
{
    if(argc <= 2){
        printf("usage: %s ip_address port_number\n", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, ip, &address.sin_addr);
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    assert(sockfd >= 0);

    int ret = bind(sockfd, (struct sockaddr *)&address, sizeof(address));
    assert(ret != -1);

    ret = listen(sockfd, 5);
    assert(ret != -1);

    struct sockaddr_in client;
    socklen_t client_len;

    int connfd = accept(sockfd, (struct sockaddr *)&client, &client_len);
    if(connfd < 0){
        printf("errno is %d\n", connfd);
    }
    else{
        int pipefd[2];
        ret = pipe(pipefd);
        assert(ret != -1);
        
        //connfd -----> pipefd[1]------>pipefd[0]
        ret = splice(connfd, NULL, pipefd[1], NULL, 32768, 0);
        assert(ret != -1);

        //pipefd[0] ----> connfd
        ret = splice(pipefd[0], NULL, connfd, NULL, 32768, 0);
        assert(ret != -1);

        close(connfd);
    }

    close(sockfd);

    return 0;
}
