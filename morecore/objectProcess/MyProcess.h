/*************************************************************************
	> File Name: MyProcess.h
	> Author: 
	> Mail: 
	> Created Time: 2015年12月14日 星期一 20时13分03秒
 ************************************************************************/

#ifndef _MYPROCESS_H
#define _MYPROCESS_H
#include <iostream>
#include <spawn.h>
#include <string>
#include <sys/wait.h>

using std::string;

class MyProcess{
    public:
        MyProcess(string path, char **av, char **ep);
        MyProcess(string path, char **av, char **ep, posix_spawn_file_actions_t psfa, posix_spawnattr_t attr);
        void run();
        void pwait(int *x);
    private:
        pid_t pid;
        posix_spawn_file_actions_t file_actions;
        posix_spawnattr_t attrp;
        char **argv;
        char **envp;
        string ProgramPath;
};
#endif
