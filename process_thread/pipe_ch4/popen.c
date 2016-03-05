/*************************************************************************
	> File Name: popen.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月05日 星期六 10时18分30秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    FILE * fp;


    char buff[1024];
    char command[1024];

    printf("输入文件名: ");
    fgets(buff, 1024, stdin);
    int len = strlen(buff);
    if(buff[len-1] = '\n')
        len--;

    snprintf(command, sizeof(command), "cat %s", buff);

    fp = popen(command, "r");

    while(fgets(buff, 1024, fp) != NULL)
        fputs(buff, stdout);


    pclose(fp);

    exit(0);
}
