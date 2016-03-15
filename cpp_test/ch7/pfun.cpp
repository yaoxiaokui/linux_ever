/*************************************************************************
	> File Name: pfun.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月15日 星期二 21时39分48秒
 ************************************************************************/

#include <iostream>
using namespace std;


void fun(int num)
{
    cout << "value = " << num << endl;
}

void (*pfun)(int num);//pfun是指向函数的指针

int main()
{
    int value = 100;

    cout << "fun: ";
    fun(value);

    pfun = &fun;//使函数指针指向函数fun, 取地址符&可以不要
    //pfun = fun;//使函数指针指向函数fun

    cout << "pfun: ";
    pfun(value);


    return 0;
}
