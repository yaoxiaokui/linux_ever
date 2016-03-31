/*************************************************************************
	> File Name: getopt.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月31日 星期四 17时18分23秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>


int main(int argc, char* argv[])
{
    printf("*****************************************\n");
    int i = 0;
    printf("共%d个命令行参数\n", argc);
    for(i = 0; i < argc; ++i){
        printf("第%d个参数是: %s\n", i+1, argv[i]);
    }
    printf("*****************************************\n");

    char ch;

    while((ch = getopt(argc, argv, "a:bc::h")) != -1){
        //printf("optind = %d, optopt = %d\n", optind, optopt);

        switch(ch){
            case 'a':
                printf("选项是%c, 选项内容: %s\n", ch, optarg);
                break;
            case 'b':
                printf("选项是%c, 选项内容: %s\n", ch, optarg);
                break;
            case 'c':
                printf("选项是%c, 选项内容: %s\n", ch, optarg);
                break;
            case 'h':
                printf("选项是%c\n", ch);
                printf("-a optstring\n");
                printf("-b\n");
                printf("-c optstring or NULL\n");
                printf("-h");
                break;
            default:
                printf("other option: %c\n", ch);
                break;
        }
    }
    return 0;
}
