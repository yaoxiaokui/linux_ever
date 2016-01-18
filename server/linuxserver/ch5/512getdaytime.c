/*************************************************************************
	> File Name: 512getdaytime.c
	> Author: 
	> Mail: 
	> Created Time: 2016年01月16日 星期六 17时55分32秒
 ************************************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    assert(argc == 2);

    char * host = argv[1];

    struct hostent * hostinfo = gethostbyname(host);
    assert(hostinfo);

    //get timeserver info 
    struct servent * servinfo = getservbyname("daytime", "tcp");
    assert(servinfo);

    printf("daytime port is %d\n", ntohs(servinfo->s_port));
    
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = servinfo->s_port;
    address.sin_addr = *(struct in_addr *)*hostinfo->h_addr_list;
    //printf("sin_port = %d\n", address.sin_port);
    //printf("sin_addr = %x\n", address.sin_addr.s_addr);

    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    int ret = connect(sockfd, (struct sockaddr *)&address, sizeof(address));

    if(ret != 0){
        printf("connected faild\n");
        return -1;
    }

    char buff[128];
    ret = read(sockfd, buff, sizeof(buff));
    assert(ret > 0);

    buff[ret] = '\0';
    printf("the time is: %s\n", buff);

    close(sockfd);

    return 0;
}
