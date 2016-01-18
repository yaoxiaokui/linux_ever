/*************************************************************************
	> File Name: 53backlog.c
	> Author: 
	> Mail: 
	> Created Time: 2016年01月16日 星期六 11时35分15秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>//包含bool类型，C语言是没有bool类型的，C++才有
#include <unistd.h>
#include <errno.h>

static bool stop = false;

static void handle_term(int sig)
{
    stop = true;
}

int main(int argc, char *argv[])
{
    signal(SIGTERM, handle_term);
    if(argc <= 2){
        printf("usage: %s ip_address port_number backlog\n", argv[0]);
        return 1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);
    int backlog = 5;//atoi(argv[3]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    assert(sock >= 0);

    //创建ipv4的地址
    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, ip, (void *)&address.sin_addr);

    int ret = connect(sock, (struct sockaddr *)&address, sizeof(address));
    if(ret < 0)
        printf("connect failed.\n");
    else{
        const char * oob_data = "abc";
        const char * normal_data = "123";
        send(sock, normal_data, strlen(normal_data), 0);
        send(sock, oob_data, strlen(oob_data), MSG_OOB);
        send(sock, normal_data, strlen(normal_data), 0);
    }

    getchar();
    printf("send over..\n");
    close(sock);

    return 0;
}
