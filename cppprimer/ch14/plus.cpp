/*************************************************************************
	> File Name: plus.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Apr 2017 01:58:37 PM CST
 ************************************************************************/

#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;



int main()
{
    plus<int> intAdd;

    int sum = intAdd(10, 20);
    cout << "sum = " << sum << endl;

    negate<int> intNegate;
    sum = intNegate(10);
    cout << "sum = " << sum << endl;


    return 0;
}
