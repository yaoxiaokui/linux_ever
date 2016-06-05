/*************************************************************************
	> File Name: program1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 05 Jun 2016 03:40:01 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

/**************************************
* 功能:该类是运算类的基类
**************************************/
class Operation
{

public:
    virtual float getResult(float num1, float num2){}
};

/**************************************
* 功能:该类实现加法
**************************************/
class OperationAdd : public Operation
{
public:
    float getResult(float num1, float num2){
        return num1 + num2;
    }
};

/**************************************
* 功能:该类实现减法
**************************************/
class OperationSub : public Operation
{
public:
    float getResult(float num1, float num2){
        return num1 - num2;
    }
};

/**************************************
* 功能:该类实现乘法
**************************************/
class OperationMul : public Operation
{
public:
    float getResult(float num1, float num2){
        return num1 * num2;
    }
};


/**************************************
* 功能:该类实现除法
**************************************/
class OperationDiv : public Operation
{
public:
    float getResult(float num1, float num2){
        return num1 / num2;
    }
};


/**************************************
* 功能:工厂类，负责生成各个运算类
**************************************/
class OperationFactory
{
public:
    static Operation * createOperation(char operate){
        switch (operate){
            case '+':
                return new OperationAdd();
            case '-':
                return new OperationSub();
            case '*':
                return new OperationMul();
            case '/':
                return new OperationDiv();
            default:
                return NULL;
        }
    }
};


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
    Operation *operation = OperationFactory::createOperation(operate);
    result = operation->getResult(num1, num2);

    cout << "结果: " << result << endl;

    delete operation;

    return 0;
}

