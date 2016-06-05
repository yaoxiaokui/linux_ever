/*************************************************************************
	> File Name: program1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 05 Jun 2016 03:40:01 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

/**************************************
*
* 功能:实现简单计算器
*
**************************************/
int main()
{
    char operate;
    float num1; 
    float num2;
    float result;

    cout << "请输入数字: ";
    cin >> num1;
    cout << "请输入运算符: ";
    cin >> operate;
    cout << "请输入数字: ";
    cin >> num2;

    switch(operate)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            cout << "运算符输入错误" << endl; 
            break;
    }

    cout << "结果: " << result << endl;

    return 0;
}

