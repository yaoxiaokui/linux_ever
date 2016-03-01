/*************************************************************************
	> File Name: echo_server_libevent.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月01日 星期二 20时28分23秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <event.h>
#include <event2/bufferevent.h>

void do_accept(evutil_socket_t listenfd, short event, void* arg);
void read_cb(struct bufferevent* bev, void* arg);
void write_cb(struct bufferevent* bev, void* arg);
void error_cb(struct bufferevent* bev, short event, void* arg);


int main(int argc, char* argv[])
{
    if(argc <= 2){
        printf("input: %s ip_address port_number\n", argv[0]);
        return -1;
    }
    int ret = 0;

    const char* ip = argv[1];
    int port = atoi(argv[2]);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0){
        printf("socket error\n");
        return -1;
    }

    evutil_make_listen_socket_reuseable(listenfd);

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);

    ret = bind(listenfd, (struct sockaddr*)&address, sizeof(address));
    if(ret < 0){
        printf("bind error\n");
        return -1;
    }

    ret = listen(listenfd, 5);
    if(ret < 0){
        printf("listen error\n");
        return -1;
    }

    printf("listening....\n");

    evutil_make_socket_nonblocking(listenfd);
    
    struct event_base* base = event_base_new();
    if(base == NULL){
        printf("event_base_new error\n");
        return -1;
    }

    struct event * listen_event;
    listen_event = event_new(base, listenfd, EV_READ | EV_PERSIST, do_accept, (void*)base);
    event_add(listen_event, NULL);
    event_base_dispatch(base);

    printf("End the server, bye\n");

    return 0;
}

void do_accept(evutil_socket_t listenfd, short event, void* arg)
{
    struct event_base* base = (struct event_base*)arg;
    evutil_socket_t fd;

    struct sockaddr_in client_addr;
    socklen_t client_addrlen = sizeof(client_addr);

    fd = accept(listenfd, (struct sockaddr*)&client_addr, &client_addrlen);
    if(fd < 0){
        printf("accept error\n");
        return;
    }

    if(fd > FD_SETSIZE){
        printf("fd > FD_SETSIZE");
        return;
    }

    printf("accept: fd = %d\n", fd);

    struct bufferevent *bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
    bufferevent_setcb(bev, read_cb, NULL, error_cb, arg);
    bufferevent_enable(bev, EV_READ | EV_WRITE | EV_PERSIST);
}


void read_cb(struct bufferevent* bev, void* arg)
{
    const int MAX_LINE = 256;
    char line[MAX_LINE+1];
    memset(line, 0, MAX_LINE+1);

    int n;
    evutil_socket_t fd = bufferevent_getfd(bev);

    while(bufferevent_read(bev, line, MAX_LINE) > 0){
        printf("fd = %d, read line: %s\n", fd, line);
        bufferevent_write(bev, line, strlen(line));
        memset(line, 0, MAX_LINE+1);
    }
}

void write_cb(struct bufferevent* bev, void* arg){}

void error_cb(struct bufferevent* bev, short event, void* arg)
{
    evutil_socket_t fd = bufferevent_getfd(bev);
    printf("fd = %d\n", fd);

    bufferevent_free(bev);
    
}
