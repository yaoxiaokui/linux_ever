/*************************************************************************
	> File Name: selectTest.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Aug 2016 07:08:57 PM CST
 ************************************************************************/

#include <iostream>
#include <sys/select.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main()
{
    int fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
    if(fd < 0){
        cerr << "open error" << endl;
        return -1;
    }

    char ch;

    fd_set read_set;

    while(1){
        FD_ZERO(&read_set);
        FD_SET(fd, &read_set);
        int ret = select(fd+1, &read_set, NULL, NULL, 0);
        if(ret > 0){

            if(FD_ISSET(fd, &read_set)){
                if(read(fd, &ch, 1) > 0){
                    if(ch == '\n')
                        continue;
                    else if(ch == 'q'){
                        break;
                    }
                    else
                        cout << "input the char is : " << ch << endl;
                }
            }
        }
        
    }


    



    return 0;
}
