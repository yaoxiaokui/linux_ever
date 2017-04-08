/*************************************************************************
	> File Name: 12printMaxNum.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jun 2016 09:36:22 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

void PrintOneToMaxNDigits(int n)
{

    int maxNum = 1;
    int i = 0;

    while(i++ < n)
        maxNum *= 10;

    for(i = 1; i < maxNum; ++i)
        cout << i << " ";

    cout << endl;
}


int main()
{
    cout << "Input the n: ";
    int n;
    cin >> n;

    PrintOneToMaxNDigits(n);

    return 0;
}
