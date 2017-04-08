/*************************************************************************
	> File Name: rttiTest1.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Aug 2016 03:56:27 PM CST
 ************************************************************************/

#include <iostream>
#include <typeinfo>
using namespace std;

class Base
{
public:
    virtual void funcA(){
        cout << "base" << endl;
    }

};

class Derived : public Base
{
public:
    virtual void funcB(){
        cout << "Derived" << endl;
    }

};

void funC(Base * p)
{
    Derived * dp = dynamic_cast<Derived*> (p);
    if(dp != NULL)
        dp->funcB();
    else 
        dp->funcA();
}

void funD(Base * p)
{
    Derived * dp = NULL;
    if(typeid(*p) == typeid(Derived)){
        cout << "typeid(*p).name = " << typeid(*p).name() << ", typeid(Derived).name() = " << typeid(Derived).name() << endl;
        dp = dynamic_cast<Derived *> (p);
        dp->funcB();
    }
    else 
        p->funcA();
}

int main()
{
    Base * cp = new Derived;
    cout << typeid(cp).name() << endl;
    cout << typeid(*cp).name() << endl;

    funD(cp);
    funC(cp);

    Base * dp = new Base;
    funD(dp);
    funC(dp);
    /*
    */
    

    return 0;
}
