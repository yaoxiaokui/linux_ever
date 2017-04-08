/*************************************************************************
	> File Name: whileCin.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Mar 2017 01:48:42 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


int main()
{
    int sum = 0;
    int val = 0;

    while(cin >> val){
        sum += val;
    }

    cout << "sum = " << sum << endl;

    return 0;
}
