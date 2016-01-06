/*************************************************************************
	> File Name: simple_fork.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月15日 星期二 14时52分24秒
 ************************************************************************/

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;


int main(int argc, char *argv[])
{
    pid_t pid;

    cout << "This is main process, PID is " << getpid() << endl;
    
    pid = fork();
    if (pid < 0){
        cout << "fork error..." << endl;
        exit(-1);
    }
    else if (pid == 0){//This is the child process
       cout << "This is child process, PID is " << getpid() << endl;
       sleep(3);//子进程休眠3秒,这样就可以看到wait函数阻塞了父进程，因为三秒之后，wait语句下面的语句才开始执行
       exit(11);//将子进程的退出码设置为11
    }
    else{//This is the main process
        cout << "This is main process waiting for the exit of child process." << endl;
        int child_status;
        pid = wait(&child_status);
        cout << "This is main process. The child status is " << child_status << ", and child pid is " << pid << ", WIFEXITED(child_status) is " << WIFEXITED(child_status) << ", WEXITSTATUS(child_status) is " << WEXITSTATUS(child_status) << endl;
    }

    exit(0);
}
