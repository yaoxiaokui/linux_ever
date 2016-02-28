/*************************************************************************
	> File Name: strlen_chararr.c
	> Author: 
	> Mail: 
	> Created Time: 2016年02月27日 星期六 10时17分37秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    char v[] = "linux_ever";
    char * p = v;
    printf("v[] = %s\n", v);
    printf("p = %s\n", p);
    printf("strlen(v) = %d\n", strlen(v));
    printf("strlen(p) = %d\n", strlen(p));

    printf("sizeof(v) = %d\n", sizeof(v));
    printf("sizeof(p) = %d\n", sizeof(p));


    return 0;
}
