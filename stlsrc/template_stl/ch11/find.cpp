/*************************************************************************
	> File Name: find.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月08日 星期五 16时38分59秒
 ************************************************************************/

#include<iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(3);
    l.push_back(1);
    l.push_back(7);

    list<int>::iterator result = find(l.begin(), l.end(), 7);
    if(result == l.end())
        cout << "not find 7" << endl;
    else
        cout << "find 7, *result = " << *result << endl;

    result = find(l.begin(), l.end(), 8);
    if(result == l.end())
        cout << "not find 8" << endl;
    else
        cout << "find 8, *result = " << *result << endl;


    return 0;
}

