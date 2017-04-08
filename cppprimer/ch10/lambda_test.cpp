/*************************************************************************
	> File Name: lambda_test.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Mar 2017 12:58:10 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
    auto f = [] { return 1234; };

    cout << f() << endl;
    cout << f() << endl;


    return 0;
}
