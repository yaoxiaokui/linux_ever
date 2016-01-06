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
#include <unistd.h>
using namespace std;


int main(int argc, char **argcgv)
{
    fstream Pipe;
    int ret;
    string input;

    Pipe.open("myPipe", ios::in | ios::out);
    if(Pipe.bad()){
        cout << "Can't open the fifo.." << endl;
    }
  
    while(!Pipe.eof() && Pipe.good()){
        getline(Pipe, input);
        cout << input << endl;
    }
    Pipe.close();
    unlink("myPipe");
    cout << "read exit..." << endl;
    exit(0);
}
