/*************************************************************************
	> File Name: fib.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月11日 星期三 19时34分44秒
 ************************************************************************/

#include<iostream>
using namespace std;

int fib(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fib(n-1) + fib(n-2);
}

int main()
{
    int n;
    cout << "input the value of n:";
    cin >> n;

    cout << "An = " << fib(n) << endl;

    return 0;
}
