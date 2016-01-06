/*************************************************************************
	> File Name: write_fifo.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月20日 星期日 20时53分29秒
 ************************************************************************/

#include <iostream>
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
    char buff[1024];
    memset(buff, 0, 1024);
    int rdfd;
    int ret = 0;

    rdfd = open("myfifo", O_RDONLY);
    if(rdfd < 0){
        cout << "open error..." << endl;
        exit(-1);
    }
    cout << "waiting for reading...\n";
    while(1){
        ret = read(rdfd, buff, 1024);
        if(ret == 0){
            cerr << "end of read..." << endl;
            break;
        }
        cout << "process "<< getpid() << " read: " << buff << endl;
        memset(buff, 0, 1024);
    }

    close(rdfd);
    exit(0);
}
