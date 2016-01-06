/*************************************************************************
	> File Name: read_shm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月21日 星期一 11时15分23秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <sys/ipc.h>
#include <string.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

/*
连接到共享内存，并向共享内存中读入数据
脱离该共享内存区域
*/
#define SHMSIZE 1024

int main(int argc, char *argv[])
{
    key_t key = 0x1111; 
   //当共享内存中有数据的时候它才会立刻返回，否则该函数会阻塞在这里 
    int shmid = shmget(key, SHMSIZE, 0666);
    if(shmid == -1){
        cerr << "shmget error ...." << endl;
        exit(-1);
    }

    pid_t pid = getpid();
    char * p = (char *)shmat(shmid, NULL, 0);
    cout << "process " << pid << " read: ";
    while(1){
        if(strlen(p) != 0)
            cout << p << endl;
        else
            continue;
        if(strcmp(p, "over") == 0){
            break;
        }
        cout << "process " << pid << " read: ";
        memset(p, 0, SHMSIZE);
    }
    cout << "进程退出。\n";
    exit(0);
}
