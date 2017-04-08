/*************************************************************************
	> File Name: FTP_CLIENT.c 
	> Author: 
	> Mail: 
	> Created Time: Sun 29 May 2016 11:47:03 AM CST
 ************************************************************************/

//该宏是提示拥有splice函数的两个宏
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if(argc < 4){
        printf("input: %s ip port file_name", argv[0]);
        return -1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);
    const char * file_name = argv[3];

    //创建socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("socket error\n");
        return -1;
    }

    //绑定socket和地址
    //先填写地址
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &servaddr.sin_addr);
    servaddr.sin_port = htons(port);


    int ret = connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if(ret < 0){
        printf("connect error\n");
        close(sockfd);
        return -1;
    }

    
    //向服务器发送要获取的文件名字
    int num = write(sockfd, file_name, strlen(file_name));
    if(num == 0){
        printf("write error\n");
        return -1;
    }

    
    //读取服务器发送的文件内容
    //先获取数据的长度
    char file_size[20];
    memset(file_size, 0, sizeof(file_size));
    read(sockfd, file_size, sizeof(file_size));

    int file_len = atoi(file_size);
    printf("file_size = %s, file_len = %d\n", file_size, file_len);

    //先创建一个文件
    printf("file_name = %s", file_name);
    int filefd = open("./t.txt", O_CREAT | O_RDONLY | O_WRONLY);
    if(filefd < 0){
        printf("create %s error\n",  file_name);
    }

    int pipefds[2];
    pipe(pipefds);

    num = splice(sockfd, NULL, pipefds[1], NULL, file_len, SPLICE_F_MOVE | SPLICE_F_MORE);

    num = splice(pipefds[0], NULL, filefd, NULL, file_len, SPLICE_F_MOVE | SPLICE_F_MORE);
    if(num > 0){
        printf("读取了%d字节的数据\n", num);
        return -1;
    }

    
    close(filefd);
    close(sockfd);


    return 0;
}
