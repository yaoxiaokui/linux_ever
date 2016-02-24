/*************************************************************************
	> File Name: practice_4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月24日 星期三 12时58分04秒
 ************************************************************************/
/*
写一个程序打印字母'a'.....'z'和数字'0'....'9',以及它们的整数值。
对其它所有可打印字符做同样的事情，再用16进制做同样的事情。
*/
#include <iostream>
using namespace std;

int main()
{
    cout << "输出字母'a'---'z':\n";
    char ch;
    for(ch = 'a'; ch <= 'z'; ++ch){
        cout << ch << ", " << dec << int(ch) << ", ";
        cout << "OX" << hex << int(ch) << endl;
    }
    cout << "输出字母'0'---'9':\n";
    for(ch = '0'; ch <= '9'; ++ch){
        cout << ch << ", " << dec << int(ch) << ", ";
        cout << "OX" << hex << int(ch) << endl;
    }
    


    return 0;
}

