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
#include <unistd.h>
using namespace std;


int main(int argc, char **argv)
{
    if(argc < 4){
        cerr << "input: pn, loop, name.\n";
        exit(-1);
    }
    int loop, pn;
    sem_t * sem;
    const char * name;
    ofstream outfile("out.txt", ios::app);

    pn = atoi(argv[1]);
    loop = atoi(argv[2]);
    name = argv[3];

    sem = sem_open(name, O_CREAT, O_RDWR, 1);
    
    for (int i = 0; i < loop; ++i){
        sem_wait(sem);
        outfile << "process: " << pn << ", counting " << i << endl;
        sem_post(sem);
    }

    sleep(3);
    outfile.close();
//    sem_unlink(name);

    exit(0);
}
