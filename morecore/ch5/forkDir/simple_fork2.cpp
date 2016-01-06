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
    int i = 0;
    cout << "This is main process, PID is " << getpid() << endl;
   
    for (i = 0; i < 2; ++i){
        
	    pid = fork();
	    if (pid < 0){
	        cout << "fork error..." << endl;
	        exit(-1);
	    }
	    else if (pid == 0){//This is the child process
	       cout << "This is child process, PID is " << getpid() << endl;
	       exit(11);//将子进程的退出码设置为11
	    }
	    else{//This is the main process
	        cout << "This is main process waiting for the exit of child process." << endl;
	    }

    }
    int child_status;
    pid_t child_pid2;
    sleep(1);//一定要等待，因为waitpid设为了无阻塞的，如果不等待，当执行完waitpid下面的语句的时候子进程2可能还没有退出，那么就得不到它的退出码了
    child_pid2 = waitpid(pid, &child_status, WNOHANG);
    cout << "This is main process. The second child status is " << child_status << ", and child pid is " << child_pid2 << ", WIFEXITED(child_status) is " << WIFEXITED(child_status) << ", WEXITSTATUS(child_status) is " << WEXITSTATUS(child_status) << endl;
		
    exit(0);
}
