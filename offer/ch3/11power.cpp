/*************************************************************************
	> File Name: 11power.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jun 2016 08:39:34 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


double Power(double base, int exponent)
{
    double result = 1.0;

    for(int i = 0; i < exponent; ++i){
        result *= base;
    }

    return result;
}


//测速主函数
int main()
{
    cout << "Input base number: ";
    double baseNumber = 0.0;
    cin >> baseNumber;

    cout << "Input exponent: ";
    int exponent = 0;
    cin >> exponent;

    double result = Power(baseNumber, exponent);
    cout << "result = " << result << endl;


    return 0;
}
