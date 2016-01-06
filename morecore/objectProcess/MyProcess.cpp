/*************************************************************************
	> File Name: MyProcess.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月14日 星期一 20时19分58秒
 ************************************************************************/

#include "MyProcess.h"
using namespace std;

MyProcess::MyProcess(string path, char **av, char **ep)
{
    ProgramPath = path;
    argv = av;
    envp = ep;
    posix_spawn_file_actions_init(&file_actions);
    posix_spawnattr_init(&attrp);
}

MyProcess::MyProcess(string path, char **av, char **ep, posix_spawn_file_actions_t psfa, posix_spawnattr_t attr)
{
    ProgramPath = path;
    argv = av;
    envp = ep;
    file_actions = psfa;
    attrp = attr;

    posix_spawn_file_actions_init(&file_actions);
    posix_spawnattr_init(&attrp);
}

void MyProcess::run()
{
    posix_spawn(&pid, ProgramPath.c_str(), &file_actions, &attrp, argv, envp);
}

void MyProcess::pwait(int *x)
{
    wait(x);
}
