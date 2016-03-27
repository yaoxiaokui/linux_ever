/*************************************************************************
	> File Name: practice_15.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月27日 星期日 22时31分02秒
 ************************************************************************/

//第十章的练习题15，修改程序，但不能修改main函数，使程序输出如下
//Initialize
//Hello, world
//Clean up

#include <iostream>

class A{
    public:
        A(){std::cout << "Initialize\n";}
        ~A(){std::cout << "Clean up\n";}

};

A a;

int main()
{
    std::cout << "Hello, world\n";
}
