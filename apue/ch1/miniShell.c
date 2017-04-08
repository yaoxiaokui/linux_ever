/*************************************************************************
	> File Name: miniShell.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Jul 2016 09:21:13 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

const int BUFF_SIZE = 1024;

int main()
{
    char buffer[BUFF_SIZE];
    memset(buffer, 0, BUFF_SIZE);

    printf("$ ");

    while(fgets(buffer, BUFF_SIZE, stdin) != NULL){
        if(buffer[strlen(buffer)-1] == '\n'){
            buffer[strlen(buffer)-1] = '\0';
        }

        pid_t pid = fork();
        if(pid == 0){//child
            execlp(buffer, buffer, NULL);
            exit(EXIT_SUCCESS);
        }
        else if(pid < 0){
            printf("fork error\n");
        }

        //下面是父进程要执行的代码
        waitpid(pid, NULL, WUNTRACED);

        printf("$ ");
    }


    return 0;
}
