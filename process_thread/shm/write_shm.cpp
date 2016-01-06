/*************************************************************************
	> File Name: write_shm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月21日 星期一 11时15分23秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
using namespace std;

/*
1: 创建一块共享内存
2：连接到共享内存，并向共享内存中写入数据
3：脱离该共享内存区域
*/
#define SHMSIZE 1024

int main(int argc, char *argv[])
{
    /*
    if(argc < 2){
        cout << "input the pathname fo generate key..."<< endl;
        exit(-1);
    }*/
    key_t key = 0x1111;//ftok(argv[1], 'a');
    
    int shmid = shmget(key, SHMSIZE, 0666|IPC_CREAT);
    if(shmid == -1){
        cerr << "shmget error ...." << endl;
        exit(-1);
    }

    char * p = (char *)shmat(shmid, NULL, 0);
    pid_t pid = getpid();
    cout << "process " << pid << " write: ";
    while(cin.getline(p, SHMSIZE)){
        if(strcmp(p, "over") == 0){
            break;
        }
        cout << "process " << pid << " write: ";
    }
//脱离该共享内存区域，并删除该共享内存区域
    shmdt(p);
    shmctl(shmid, IPC_RMID, NULL);
    cout << "已经删除了共享内存，并退出。\n";
    exit(0);
}
