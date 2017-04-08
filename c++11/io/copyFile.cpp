/*************************************************************************
	> File Name: copyFile.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 06 Aug 2016 02:51:08 PM CST
 ************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv[])
{

    ifstream from(argv[1]);
    if(!from){
        cerr << "open error" << endl;
        return -1;
    }

    ofstream to(argv[2]);
    if(!to){
        cerr << "open error" << endl;
        return -1;
    }

    char ch;

    while(from.get(ch)){
        to.put(ch);
    }


    return 0;
}

