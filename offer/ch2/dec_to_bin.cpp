/*************************************************************************
	> File Name: dec_to_bin.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Jun 2016 07:29:27 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


int fun(int n)
{
    int count = 0;

    while(n!=0 && n!=1){
        n = n >> 2;

    }
}

int main()
{

    cout << "n = ";
    int n;
    cin >> n;

    cout << fun(n) << endl;


    return 0;
}
