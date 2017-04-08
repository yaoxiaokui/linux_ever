/*************************************************************************
	> File Name: while.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Mar 2017 01:44:48 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int sum = 0, val = 1;

    while(val <= 10){
        sum += val;
        val++;
    }

    cout << "sum = " << sum << endl;

    return 0;
}
