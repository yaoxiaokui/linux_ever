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
* 功能:该类实现运算
*
**************************************/

class Operation
{

public:
    float getResult(float num1, char operate, float num2);
};


/****************************************************************
*   函数名称：getResult(float num1, char operate, float num2)
*   功能描述: 返回num operate num2 操作之后的结果
*   参数列表: num1为值1，operate为操作运算，num2为值2
*   返回结果：成功返回运算结果，失败返回0.0
*****************************************************************/
float Operation::getResult(float num1, char operate, float num2)
{
    float result = 0.0;

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
            if(num2 == 0)
                cout << "除数不能为0." << endl;

            result = num1 / num2;
            break;
        default:
            cout << "运算符输入错误" << endl; 
            break;
    }

    return result;
}

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

    //创建运算类对象
    Operation operation;
    result = operation.getResult(num1, operate, num2);

    cout << "结果: " << result << endl;

    return 0;
}

