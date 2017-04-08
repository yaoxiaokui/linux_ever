/*************************************************************************
	> File Name: useFstream.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Mar 2017 04:50:32 PM CST
 ************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream f1;
    f1.open("./data.txt");

    fstream f2;
    f2.open("./data.txt.back");
    if(f2){
        cout << "data.txt.back open ok" << endl;
    }
    else{
        cout << "data.txt.back open is not ok" << endl;
    }

    string str;
    while(f1 >> str){
        cout << "str: " << str << endl;
        f2 << str << endl;
    }

    f1.close();
    f2.close();

    return 0;
}

