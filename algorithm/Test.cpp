/*************************************************************************
	> File Name: Test.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Aug 2016 04:04:11 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Test{

public:
    const int value;
    Test(int n):value(9){}
    Test():value(100){}
    void fun(){ cout << "value = " << value << endl; }
};

int main()
{
    Test a(1);
    a.fun();


    return 0;
}
