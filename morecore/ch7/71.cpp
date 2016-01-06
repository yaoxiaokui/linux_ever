/*************************************************************************
	> File Name: 71.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月17日 星期四 18时55分38秒
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>

using namespace std;


int main(int argc, char **argcgv)
{
    fstream Pipe;
    int ret;
    string input;

    ret = mkfifo("myPipe", S_IRUSR|S_IWUSR);
    if(ret != 0){
        cout << "mkfifo error..." << endl;
        exit(-1);
    }

    Pipe.open("myPipe", ios::out);
    if(Pipe.bad()){
        cout << "Can't open the fifo.." << endl;
    }
    else{
        while(cin >> input){
            Pipe << input << endl;
        }
        //Pipe << "1 2 3 4 5 6 7 8 9" << endl;
    }
   
    cout << "write exit..." << endl;
    exit(0);
}
