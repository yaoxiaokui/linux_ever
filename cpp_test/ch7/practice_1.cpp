/*************************************************************************
	> File Name: practice_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月15日 星期二 22时35分36秒
 ************************************************************************/

#include <iostream>
using namespace std;

//以指向字符的指针和对整数的引用为参数,不返回值
void fun1(char *ch, int & rval);//形参ch， rval可以没有

//指向上面函数fun1的函数指针
typedef void (*pfun1)(char* ch, int & rval);
pfun1 pf = fun1;//pf就是指向上面函数fun1的指针

//一个以pfun1指针为参数的函数
void fun2(pfun1);//形参可以没有

//一个返回pfun1类型指针的函数 
pfun1 fun3();

//一个函数，以fun1类型的指针作为参数，以fun1类型的指针作为返回值
pfun1 fun4(pfun1 pf)
{
    return pf;
}


int main()
{
    char* str = "cplusplus";
    int val = 100;

    cout << "调用fun1(str,val)：";
    fun1(str, val);

    pfun1 pf1 = fun1;
    cout << "调用pf1(str, val): ";
    pf1(str, val);

    pfun1 pf2 = fun4(pf1);
    cout << "调用pf(str, val): ";
    pf(str, val);
    

    return 0;
}

void fun1(char* ch, int & rval)
{

    cout << "ch = " << ch << ", rval++ = " << rval++ << endl;
}
