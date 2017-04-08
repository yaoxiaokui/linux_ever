/*************************************************************************
	> File Name: all_of.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 27 Jul 2016 11:59:56 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;


template<typename T>
bool myFun(T t)
{
    return (t % 2) == 1;
}


int main()
{
    vector<int> v{1, 3, 5, 7, 9};

    bool isOdd = all_of(v.begin(), v.end(), myFun<int>);
    if(isOdd)
        cout << "all element are odd" << endl;


    return 0;
}

