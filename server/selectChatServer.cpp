/*************************************************************************
	> File Name: selectChatServer.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Aug 2016 07:45:44 PM CST
 ************************************************************************/

#include <iostream>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
using namespace std;

int main(int argc, char * argv[])
{
    if(argc < 3){
        cout << "input: " << argv[0] << ", ip, port" << endl;
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);


    //创建套接字
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0){
        cerr << "socket error" << endl;
    }
    
    //绑定套接字和地址
    sockaddr_in serverAddr;
    bzero(&serverAddr, sizeof(serverAddr));

    serverAddr.sin_port = htons(port);
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &serverAddr.sin_addr);

    int ret = bind(listenfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if(ret < 0){
        cerr << "bind error" << endl;
        close(listenfd);
        return -1;
    }

    //监听套接字
    ret = listen(listenfd, 5);
    if(ret < 0){
        cerr << "listen error" << endl;
        close(listenfd);
        return -1;
    }

    while(1){


    }


    return 0;
}
