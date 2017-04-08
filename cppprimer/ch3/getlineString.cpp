/*************************************************************************
	> File Name: getlineString.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Mar 2017 06:40:43 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while(getline(cin, str)){
        cout << str << endl;
    }

    return 0;
}

