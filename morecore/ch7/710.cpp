/*************************************************************************
	> File Name: 79.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月18日 星期五 16时26分44秒
 ************************************************************************/

#include <iostream>
#include <semaphore.h>
#include <fstream>
#include <cstdlib>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>

using namespace std;


int main(int argc, char **argv)
{
    if(argc < 2){
        cerr << "input: name.\n";
        exit(-1);
    }
    string str;
    sem_t * sem;
    const char * name;
    ifstream infile("out.txt");

    if(infile.is_open()){
        name = argv[1];
        sem = sem_open(name, O_CREAT, O_RDWR, 1);
        
        while(!infile.eof() && infile.good()){
            sem_wait(sem);
            getline(infile, str);
            cout << str << endl;
            sem_post(sem);
        }
        cout << "........................................" << endl;
        infile.close();
    }
    
//    sem_unlink(name);

    exit(0);
}
