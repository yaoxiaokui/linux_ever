/*************************************************************************
	> File Name: vfork.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月18日 星期三 22时11分33秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
        int fd;
        pid_t pid;
        signal(SIGCHLD, SIG_IGN);
        printf("befor fork pid:%d \n", getpid());

       // g_num = 10;

        pid = vfork();
        if (pid == -1)
    {
                printf("pid < 0 err.\n");
                return -1;
            
    }
        
    if (pid > 0)
    {
        printf("parent: pid:%d \n", getpid());
            
    }
    else if (pid == 0)
    {
        printf("child: %d, parent: %d \n", getpid(), getppid());
                
        // int execve(const char *filename, char *const argv[],
        //                   char *const envp[]);
        //
        char *const argv[] = {"ls", "-lt", NULL};
        execve("/bin/ls", argv, NULL);
        //                              
        //                                      //注意：此处有/bin/ls程序结束程序，不会出现coredump现象
        //                                              
        printf("测试下面这句话还执行吗\n");
        //                                                              //exit(0);
        //                                                                      //1 vfork只有需要用exit(0) _exit(0) 
        //                                                                              //2 测试return 0; 区别
        //                                                                                  
    }

    printf("fork after....\n");
    return 0;

}

