/*************************************************************************
	> File Name: useposix_spawn2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月14日 星期一 14时21分52秒
 ************************************************************************/

#include <iostream>
#include <spawn.h>
#include <string.h>
#include <sys/wait.h>
#include <cstdlib>
#include <error.h>

using namespace std;

/*
    #include <spawn.h>

    int posix_spawn(pid_t *restrict pid, const char *restrict path,
                                    const posix_spawn_file_actions_t *file_actions,
                                    const posix_spawnattr_t *restrict attrp,
                                    char *const argv[restrict], char *const envp[restrict]);
*/

int main(int argc, char *argv[])
{
    pid_t child_pid[2];
    int ret;
    int wait_val[2];

    cout << "This is main process......" << endl;
    ret = posix_spawn(&child_pid[0], "ls", NULL, NULL, argv, NULL);
    if (ret != 0){
        cout << "posix_spawn is error" << endl;
        exit(-1);
    }

    ret = posix_spawn(&child_pid[1], "cat", NULL, NULL, argv, NULL);
    if (ret != 0){
        cout << "posix_spawn is error" << endl;
        exit(-1);
    }
    wait(&wait_val[0]);
    cout << "This is main process and the wait value of ls is " << wait_val[0] << endl;
    wait(&wait_val[1]);
    cout << "This is main process and the wait value of cat is " << wait_val[1] << endl;

    exit(0);
}
