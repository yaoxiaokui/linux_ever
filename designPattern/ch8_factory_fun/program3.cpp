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

/*----------------------------------------------------------------*/

/**************************************
* 功能:抽象工厂基类
**************************************/
class OperationFactory
{
public:
    virtual Operation * createOperation() = 0;
};

/**************************************
* 功能:加法工厂类
**************************************/
class AddFactory : public OperationFactory
{
public:
    Operation * createOperation(){
        return new OperationAdd();
    }
};

/**************************************
* 功能:减法工厂类
**************************************/
class SubFactory : public OperationFactory
{
public:
    Operation * createOperation(){
        return new OperationSub();
    }
};

/**************************************
* 功能:乘法工厂类
**************************************/
class MulFactory : public OperationFactory
{
public:
    Operation * createOperation(){
        return new OperationMul();
    }
};

/**************************************
* 功能:除法工厂类
**************************************/
class DivFactory : public OperationFactory
{
public:
    Operation * createOperation(){
        return new OperationDiv();
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
    cout << "输入运算符: ";
    cin >> operate;
    cout << "请输入数字: ";
    cin >> num2;

    Operation * operation = NULL;
    OperationFactory * factory = NULL;
    //创建运算类对象
    switch(operate){

    case '+':
        factory = new AddFactory();
        break;

    case '-':
        factory = new SubFactory();
        break;
    case '*':
        factory = new MulFactory();
        break;
    case '/':
        factory = new DivFactory();
        break;
    default:
        break;
    }

    operation = factory->createOperation();
    result = operation->getResult(num1, num2);
    cout << "结果: " << result << endl;

    if(operation)
        delete operation;

    if(factory)
        delete factory;

    return 0;
}

