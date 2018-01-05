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

int main()
{
    lm::helloworld msg;
    msg.set_id(100);
    msg.set_str("hello world");

    fstream output("./helloworld.log", ios::out | ios::trunc | ios::binary);

    if(!msg.SerializeToOstream(&output)){
        cerr << "Fatail to write msg." << endl;
        return -1;
    }


    return 0;
}

