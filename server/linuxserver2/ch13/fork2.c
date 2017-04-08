/*************************************************************************
	> File Name: fork.c
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Jun 2016 10:11:10 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

//父进程创建2个子进程
const int child_num = 2;

int main()
{
    int child_pids[child_num];
    int i = 0;

    //创建两个进程
    //此时和之前一种情况的区别在于，子进程1不是直接休眠然后退出，
    //而是会执行for循环（初始值i=1），所以子进程1还会再创建一个子进程
    //程序总共会生成4个进程（包括父进程）
    for(i = 0; i < child_num; ++i){
        child_pids[i] = fork();
        if(child_pids[i] == 0){
            printf("子进程%d, pid = %d\n", i+1, getpid());
        }
        else if(child_pids[i] > 0){
            printf("父进程pid = %d, 子进程pid = %d\n", getpid(), child_pids[i]);
        }
        else{
            printf("fork error\n");
        }
    }

    sleep(10);//睡眠一下，为了用ps查看它们的pid


    return 0;
}
