/*************************************************************************
	> File Name: getcwd.c
	> Author: 
	> Mail: 
	> Created Time: 2016年01月18日 星期一 13时42分36秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("get current work directioy: ");
    char dirbuff[128];
    char * ret = getcwd(dirbuff, 128);
    if(ret == NULL){
        return -1;
    }

    printf("%s\n", dirbuff);

    printf("change current work directioy to ~/linux_ever/server/linuxserver\n");;
    int result = chdir("~/linux_ever/server/linuxserver");
    if(result < 0){
        return -1;
    }

    printf("get current work directioy: ");
    ret = getcwd(dirbuff, 128);
    if(ret == NULL){
        return -1;
    }

    printf("%s\n", dirbuff);



    return 0;
}
