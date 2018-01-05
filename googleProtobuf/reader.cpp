/*************************************************************************
	> File Name: writer.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月24日 星期日 21时38分22秒
 ************************************************************************/

#include <iostream>
#include <fstream>
#include "lm.helloworld.pb.h"
using namespace std;


void PrintMsg(lm::helloworld & msg)
{
    cout << "id: " << msg.id() << endl;
    cout << "str: " << msg.str() << endl;
}


int main()
{
    lm::helloworld msg;

    fstream input("./helloworld.log", ios::in | ios::binary);

    if(!msg.ParseFromIstream(&input)){
        cerr << "Fatail to read msg." << endl;
        return -1;
    }

    PrintMsg(msg);


    return 0;
}

