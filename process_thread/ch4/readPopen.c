/*************************************************************************
	> File Name: popen.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月22日 星期五 21时28分40秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    char command[1024];
    memset(buffer, 0, 1024);
    memset(command, 0, 1024);

    //输入命令
    printf("Input the command: ");
    fgets(command, 1024, stdin);
    //去除换行符号
    int n = strlen(command);
    if(command[n] = '\n'){
        //command[n] = 0;//一定要赋值为0，不能是'0'
        command[n] = '\0';//一定要赋值为0，或是'\0', 不能是'0'
    }

    //调用popen执行命令
    //type='r',命令的标准输出会输出到管道，以fp引出来
    FILE * fp = popen(command, "r");
    if(fp == NULL){
        printf("popen error\n");
        return -1;
    }

    printf("输出command的标准输出: ");
    //从fp中读取命令的标准输出
    while(fgets(buffer, 1024, fp) != NULL)
        fputs(buffer, stdout);
    
    pclose(fp);

    return 0;
}
