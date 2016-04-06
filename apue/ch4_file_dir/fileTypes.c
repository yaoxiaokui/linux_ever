/*************************************************************************
	> File Name: fileTypes.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月06日 星期三 09时25分04秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, char * argv[])
{
    int i = 0;
    struct stat fileInfo;
    char *ptr = NULL;

    for(i = 1; i < argc; ++i){
        lstat(argv[i], &fileInfo);

        if(S_ISREG(fileInfo.st_mode))
            ptr = "普通文件";
        else if(S_ISDIR(fileInfo.st_mode))
            ptr = "目录文件";
        else  if(S_ISCHR(fileInfo.st_mode))
            ptr = "字符文件";
        else if(S_ISBLK(fileInfo.st_mode))
            ptr = "块特殊文件";
        else if(S_ISFIFO(fileInfo.st_mode))
            ptr = "FIFO文件";
        else if(S_ISLNK(fileInfo.st_mode))
            ptr = "符号链接文件";
        else if(S_ISSOCK(fileInfo.st_mode))
            ptr = "管道文件";

        if(ptr != NULL)
            printf("%s\n", ptr);
    }

    return 0;
}
