/*************************************************************************
	> File Name: write_fifo.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月20日 星期日 20时53分29秒
 ************************************************************************/

#include<iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
using namespace std;

/*
1:创建命名管道
2:从标准输入输入内容到buffer中
3:打开命名管道，将buffer中的内容写入到命名管道中
*/

int main()
{
    int ret = mkfifo("myfifo", 0666);
    if(ret < 0){
        cerr << "mkfifo error..." << endl;
        exit(-1);
    }
    char buff[1024];
    memset(buff, 0, 1024);
    int wrfd;
    cout << "wating for another process open the myfifo to reading..."<< endl;
    wrfd = open("myfifo", O_WRONLY);
    if(wrfd == -1){
        cerr << "open error..." << endl;
        exit(-1);
    }
    pid_t pid = getpid();
    cout << "process " << pid << " write: ";
    while(cin.getline(buff, 1024)){
        write(wrfd, buff, strlen(buff));
        memset(buff, 0, 1024);
        cout << "process " << pid << " write: ";
    }

    close(wrfd);
    exit(0);
}
