/*************************************************************************
	> File Name: virtual_function.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月30日 星期三 10时10分17秒
 ************************************************************************/

//测试虚函数的使用，以及多态性.公有继承
#include <iostream>
#include <string>
#include <list>
using namespace std;


//基类Employee
class Employee{
    private:
        string first_name;
        string family_name;
    public:
        Employee(const string & s1, const string s2):first_name(s1), family_name(s2){}
        //void print() const;//如果该函数不是virtual，则main函数中ep->print()将调用基类的函数
        virtual void print() const;
};

void Employee::print() const
{
    cout << "first_name: " << first_name << ", family_name: " << family_name << endl;
}

//派生类Manager(经理类，它同时也是雇员，所以应该从Employee类派生)
class Manager:public Employee{
    private:
        int level;//级别
    public:
        Manager(const string & s1, const string s2, int l):Employee(s1, s2), level(l){}
        void print() const;
    
};

void Manager::print() const
{
    Employee::print();
    cout << "Manager level = " << level << endl;
}



//主函数测试该
int main()
{
    
    Employee e("linux", "ever");
    e.print();

    Manager m("c", "c++", 10);
    m.print();

    Employee * ep = &m;//派生类的地址可以赋值给基类的指针
    ep->print();

    //Manager * mp = &e;//基类的地址不能赋值给派生类的指针

    return 0;
}

