/*************************************************************************
	> File Name: hash.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月13日 星期三 10时40分38秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;

int main()
{    hash<const char *> H;

    cout << "foo-> " << H("foo") << endl;
    cout << "bar-> " << H("bar") << endl;

    return 0;
}

