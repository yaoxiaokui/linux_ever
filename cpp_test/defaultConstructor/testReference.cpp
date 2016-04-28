/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月28日 星期四 10时47分26秒
 ************************************************************************/

#include <iostream>
using namespace std;



int main()
{

    char ch = 'a';

    char * pch = &ch;
    char & rch = ch;

    cout << "ch = " << ch << endl;
    cout << "*pch = " << *pch << endl;
    cout << "rch = " << rch << endl;

    cout << "sizeof(ch) = " << sizeof(ch) << endl;
    cout << "sizeof(pch) = " << sizeof(pch) << endl;
    cout << "sizeof(rch) = " << sizeof(rch) << endl;

    return 0;
}
