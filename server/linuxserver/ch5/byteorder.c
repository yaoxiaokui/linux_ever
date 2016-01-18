/*************************************************************************
	> File Name: byteorder.c
	> Author: 
	> Mail: 
	> Created Time: 2016年01月16日 星期六 10时28分26秒
 ************************************************************************/

#include<stdio.h>

union{
    short value;
    char ch_val[sizeof(short)];
}byteval;

int main()
{

    byteval.value = 0x1234;
    if(byteval.ch_val[0] == 0x12 && byteval.ch_val[1] == 0x34){
        printf("大段存储\n");
    }
    else if(byteval.ch_val[0] == 0x34 && byteval.ch_val[1] == 0x12){
        printf("小端存储\n");
    }
    else{
        printf("不知道的结构\n");
    }

    return 0;
}
