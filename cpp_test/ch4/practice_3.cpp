/*************************************************************************
	> File Name: practice_3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月24日 星期三 12时37分02秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    cout << "sizeof(bool) = " << sizeof(bool) << endl;
    cout << "sizeof(char) = " << sizeof(char) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(float) = " << sizeof(float) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(long double) = " << sizeof(long double) << endl;

    enum e{a, b=3};

    cout << "sizeof(enum) = " << sizeof(e) << endl;
    cout << "sizeof(int *) = " << sizeof(int *) << endl;
    cout << "sizeof(char *) = " << sizeof(char *) << endl;


    return 0;
}
