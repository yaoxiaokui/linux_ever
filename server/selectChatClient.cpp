/*************************************************************************
	> File Name: selectChatClient.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Aug 2016 07:54:47 PM CST
 ************************************************************************/

#include <iostream>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>
using namespace std;

int main(int argc, char * argv[])
{
    if(argc < 3){
        cerr << "input: " << argv[0] << ", ip, port" << endl;
        return -1;
    }


    const char *ip = argv[1];
    int port = atoi(argv[2]);

    //创建套接字
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        cerr << "socket error" << endl;
        return -1;
    }

    //获得服务器监听的地址
    sockaddr_in serverAddr;
    bzero(&serverAddr, sizeof(serverAddr));

    serverAddr.sin_port = htons(port);
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &serverAddr.sin_addr);

    //连接到服务器
    int ret = connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(ret < 0){
        cerr << "connect error" << endl;
        return -1;
    }

    char buffer[1024];

    while(1){
        memset(buffer, 0, sizeof(buffer));

        read(sockfd, buffer, sizeof(buffer));
        

    }


    return 0; 
}
