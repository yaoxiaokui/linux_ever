/*************************************************************************
	> File Name: system.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月15日 星期二 16时46分16秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
    int status;
    cout << "This is main process..." << endl;
    status = system("ls -l");
    //status = system("ls");
    if(status < 0){
        cout << "system is error." << endl;
        exit(-1);
    }

    cout << "WEXITSTATUS(status) is " << WEXITSTATUS(status) << endl;
    exit(0);
}
