/*************************************************************************
	> File Name: search.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月09日 星期六 11时31分13秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    const char * str1 = "hello world";
    const char * str2 = "world";

    const int n1 = strlen(str1);
    const int n2 = strlen(str2);

    const char * p = search(str1, str1+n1, str2, str2+n2);
    if(p != str1 + n1)
        cout << "*p = " << *p << ", *(p+n2-1) = " << *(p+n2-1) << ", substr length is " << n2 << endl;
    else
        cout << "can't find world" << endl;

    return 0;
}

