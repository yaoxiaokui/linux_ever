/*************************************************************************
	> File Name: 211.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月11日 星期三 19时29分56秒
 ************************************************************************/

#include<iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return n*fact(n-1);
}

int main()
{
    cout << "input the num of n:";
    int n;
    cin >> n;

    cout << "n! = " << fact(n) << endl;

    return 0;
}
