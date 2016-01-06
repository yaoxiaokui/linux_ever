/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月14日 星期一 20时04分46秒
 ************************************************************************/

#include "MyProcess.h"
#include <cstdlib>
using namespace std;

#define PROCESSNUM 2

int main(int argc, char *argv[])
{
    int wait_val[2];

    if (argc < 2){
        cout << "the argc is less than 3" << endl;
        exit(-1);
    }

    MyProcess child1("ls", argv, NULL);
    MyProcess child2("/bin/ps", argv, NULL);
    
    child1.run();
    child2.run();
    
    child1.pwait(&wait_val[0]);
    child1.pwait(&wait_val[1]);
   
    cout << "child1.pwait is " << wait_val[0] << endl;
    cout << "child2.pwait is " << wait_val[1] << endl;

    exit(0);
}

