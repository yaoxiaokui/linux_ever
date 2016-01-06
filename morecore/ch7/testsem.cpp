/*************************************************************************
	> File Name: testsem.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月18日 星期五 17时02分49秒
 ************************************************************************/

#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
using namespace std;

int main(int argc, char **argv)
{
    char *name = argv[1];
    key_t key;
    key = ftok(name, 'a');
    int ret = semget(key, 4, IPC_CREAT);
    cout << "ret is " << ret << endl;


    return 0;
}


