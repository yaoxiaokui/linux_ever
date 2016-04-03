/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月03日 星期日 15时51分33秒
 ************************************************************************/

#include <stdio.h>


int mymax(int a, int b);
int add(int a, int b);

int main()
{
    int a = 10;
    int b = 20;

    int c = mymax(a, b);
    printf("c = %d\n", c);
    printf("add(10, 20) = %d\n", add(10, 20));
    printf("hello world\n");

    return 0;
}
