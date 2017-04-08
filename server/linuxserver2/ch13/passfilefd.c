/*************************************************************************
	> File Name: passfilefd.c
	> Author: 
	> Mail: 
	> Created Time: Tue 14 Jun 2016 10:11:58 AM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

static const int CONTROL_LEN = CMSG_LEN(sizeof(int));


/****************************************************************
*   函数名称：send_fd(int fd, int fd_to_send)
*   功能描述: 发送文件描述符  
*   参数列表: fd是用来传递信息的UNIX域socket;
*             fd_to_send是待发送的文件描述符
*   返回结果：无
*****************************************************************/
void send_fd(int fd, int fd_to_send)
{
    struct iovec iov[1];
    struct msghdr msg;

    char buf[0];

    iov[0].iov_base = buf;
    iov[0].iov_len = 1;

    msg.msg_name = NULL;
    msg.msg_namelen = 0;
    msg.msg_iov = iov;
    msg.msg_iovlen = 1;

    struct cmsghdr cm;
    cm.cmsg_len = CONTROL_LEN;
    cm.cmsg_level = SOL_SOCKET;
    cm.cmsg_type = SCM_RIGHTS;

    *(int *)CMSG_DATA(&cm) = fd_to_send;
    msg.msg_control = &cm;//设置辅助数据
    msg.msg_controllen = CONTROL_LEN;
    
    sendmsg(fd, &msg, 0);
}


/****************************************************************
*   函数名称：recv_fd(int fd)
*   功能描述: 接收文件描述符  
*   参数列表: fd是用来传递信息的UNIX域socket;
*   返回结果：返回接收到的文件描述符
*****************************************************************/
int recv_fd(int fd)
{
    struct iovec iov[1];
    struct msghdr msg;
    char buf[0];

    iov[0].iov_base = buf;
    iov[0].iov_len = 1;

    msg.msg_name = NULL;
    msg.msg_namelen = 0;
    msg.msg_iov = iov;
    msg.msg_iovlen = 1;

    struct cmsghdr cm;

    msg.msg_control = &cm;
    msg.msg_controllen = CONTROL_LEN;
    //接收文件描述符
    recvmsg(fd, &msg, 0);

    int fd_to_recv = *(int *)CMSG_DATA(&cm);

    return fd_to_recv;
}



/****************************************************************
*   函数名称：main
*   功能描述: 主函数用来测试进程间传递文件描述符
*   参数列表: 
*   返回结果:
*****************************************************************/
int main()
{
    int pipefd[2];
    int fd_to_pass = 0;

    //创建父、子进程间的管道，文件描述符pipefd[0]和pipefd[1]都是UNIX域的socket.h
    int ret = socketpair(PF_UNIX, SOCK_DGRAM, 0, pipefd);
    if(ret != 0){
        printf("socketpair error\n");
        return -1;
    }

    //创建子进程
    pid_t pid = fork();
    if(pid == 0){//子进程向pipefd[1]中写入文件描述符

        close(pipefd[0]);

        //打开文件，创建一个文件描述符
        fd_to_pass = open("test.txt", O_RDWR, 0666);
        if(fd_to_pass < 0){
            printf("open test.txt error\n");
            close(pipefd[1]);
            return -1;
        }

        //发送文件描述符
        send_fd(pipefd[1], fd_to_pass);
        
        close(fd_to_pass);
        close(pipefd[1]);
    }
    else if(pid > 0){//父进程
        close(pipefd[1]);
        //父进程从管道中读取文件描述符
        fd_to_pass = recv_fd(pipefd[0]);

        char buff[1024];
        memset(buff, 0, sizeof(buff));

        //向接收的文件描述符中读取数据
        read(fd_to_pass, buff, sizeof(buff));
        printf("父进程读取的数据: %s\n", buff);

        close(fd_to_pass);
        close(pipefd[0]);
    }
    else{
        printf("创建子进程失败\n");
        close(pipefd[0]);
        close(pipefd[1]);
    }


    return 0;
}
