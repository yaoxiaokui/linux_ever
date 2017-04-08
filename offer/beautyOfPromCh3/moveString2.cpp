/*************************************************************************
	> File Name: moveString2.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Aug 2016 10:04:09 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void fun(string & s1, string & s2)
{
    int len = s1.size();

    for(int i = 0; i < len; ++i){
        //向左移动一位
        char temp = s1[0];
        for(int i = 0; i < len-1; ++i){
            s1[i] = s1[i+1];
        }
        s1[len-1] = temp;

        if(strstr(s1.c_str(), s2.c_str()) != 0){
            cout << "s1 contain s2" << endl;
            return ; 
        }
    }
    cout << "s1 not contain s2" << endl;
}


void fun2(string & s1, string & s2)
{
    s1 += s1;

    if(strstr(s1.c_str(), s2.c_str()) != 0){
        cout << "s1 contain s2" << endl;
    }
    else
        cout << "s1 not contain s2" << endl;
}


int main()
{
    string s1, s2;
    cout << "input the s1: ";
    cin >> s1;
    cout << "input the s2: ";
    cin >> s2;

    fun(s1, s2);
    fun2(s1, s2);

    return 0;
}

