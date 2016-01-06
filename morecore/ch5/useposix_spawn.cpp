/*************************************************************************
	> File Name: useposix_spawn.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月14日 星期一 19时45分21秒
 ************************************************************************/

#include <iostream>
#include <spawn.h>
#include <sys/wait.h>
using namespace std;

int main()
{
    posix_spawn_file_actions_t psfa;
    posix_spawnattr_t ps;

    pid_t pid;
    char *argv[] = {"/bin/ps", "-lf", NULL};
    char *envp[] = {"PROCESSES=2"};

    posix_spawn_file_actions_init(&psfa);
    posix_spawnattr_init(&ps);

    posix_spawn(&pid, "/bin/ps", &psfa, &ps, argv, envp);
    cout << "pid is " << pid << endl;
    int wait_val;
    wait(&wait_val);

    return 0;
}
