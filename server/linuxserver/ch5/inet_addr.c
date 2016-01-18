/*************************************************************************
	> File Name: inet_addr.c
	> Author: 
	> Mail: 
	> Created Time: 2016年01月16日 星期六 10时53分27秒
 ************************************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    printf("\n********************\n");
    printf("inet_addr and inet_ntoa\n");

    in_addr_t int_addr = inet_addr("127.0.0.1");
    printf("将127.0.0.1转为网络字节序存放在int_addr中，下面是结果\n");
    printf("in_addr_t = %x\n", int_addr);

    struct in_addr addr;
    addr.s_addr = int_addr;
    char * str_addr = inet_ntoa(addr);

    printf("str_addr = %s\n", str_addr);


    printf("\n********************\n");
    printf("inet_pton and inet_ntop\n");

    int ret = inet_pton(AF_INET, "192.168.0.1", (void *)&int_addr);
    if(ret == 0)
        return 0;

    printf("将192.168.0.1转为网络字节序存放在int_addr中，下面是结果\n");
    printf("in_addr_t = %x\n", int_addr);

    
    char * dest;
    const char * pret = inet_ntop(AF_INET, (void *)&int_addr, dest, INET_ADDRSTRLEN);
    if(pret == NULL)
        return 0;

    printf("dest = %s\n", dest);



    return 0;
}

