/*************************************************************************
	> File Name: 11power.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jun 2016 08:39:34 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//判断两个浮点数是否相等
bool equal(double number1, double number2)
{
    if((number1-number2 > -0.0000001) && (number1-number2 < 0.0000001))
        return true;
    else
        return false;
}

//求次方数为正的情况,递归实现
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;

    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;//注意此句

    //如果exponent是奇数
    if(exponent & 0x1 == 1)
        result *= base;

    return result;
}

//该变量标识输入是否非法
bool invailedInput = false;

//求次方的函数
double Power(double base, int exponent)
{
    invailedInput = false;

    double result = 1.0;

    if(equal(base, 0.0) && exponent < 0){
        invailedInput = true;
        return 0.0;
    }

    unsigned int unsignedExponent = (unsigned int)exponent;

    //当次方数为负数的情况
    if(exponent < 0)
        unsignedExponent = (unsigned int)(-exponent);

    
    result = PowerWithUnsignedExponent(base, unsignedExponent);

    //当次方数为负数的情况
    if(exponent < 0)
        result = 1.0/result;

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

    if(invailedInput)
        cout << "非法输入" << endl;

    return 0;
}
