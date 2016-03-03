/*************************************************************************
	> File Name: stat_ftok.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月03日 星期四 21时35分22秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/ipc.h>

int main(int argc, char* argv[])
{
    if(argc < 2){
        printf("input: %s file_name\n", argv[0]);
        return -1;
    }

    struct stat st;

    int ret = stat(argv[1], &st);
    if(ret < 0){
        printf("stat error\n");
        return -1;
    }

    printf("stat.st_dev = %lx, stat.st_ino = %lx, key = %x\n", (u_long)st.st_dev, (u_long)st.st_ino, ftok(argv[1], 0x57));

    return 0;
}
