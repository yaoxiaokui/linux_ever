/*************************************************************************
	> File Name: getpwnam.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月15日 星期二 19时08分36秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>


void sig_handler(int sig_num)
{
    struct passwd * ptr;
    
    if((ptr = getpwnam("linux_ever")) == NULL){
        printf("getpwnam error\n");
        return;
    }

    printf("receive the signal %d, user name is %s\n", sig_num, ptr->pw_name);

    alarm(1);
}

int main()
{
    struct passwd* ptr;
    
    
    signal(SIGALRM, sig_handler);
    alarm(1);

    for(; ;){
        if((ptr = getpwnam("root")) == NULL){
            printf("getpwnam error\n");
            return -1;
        }

        if(strcmp(ptr->pw_name, "root") != 0){
            printf("main:主函数里的getpwnam与信号处理函数里的getpwnam冲突了。。user name is %s\n", ptr->pw_name);
        }
    }


    return 0;
}
