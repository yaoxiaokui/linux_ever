/*************************************************************************
	> File Name: 5_5_strlen.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月28日 星期日 11时43分35秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    char str[] = "a short string";
    cout << "str = " << str << endl;
    cout << "strlen(str) = " << strlen(str) << endl;

    cout << "sizeof(str) = " << sizeof(str) << endl;

    return 0;
}
