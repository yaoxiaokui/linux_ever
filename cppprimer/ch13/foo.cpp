/*************************************************************************
	> File Name: foo.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 30 Mar 2017 03:40:19 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Foo{

public:
    Foo();
    Foo(const Foo & other);
    Foo & operator=(const Foo & other);

private: 
    int count;
};


Foo::Foo()
{
    count = 0;
}

Foo::Foo(const Foo & other)
{
   count = other.count;
}

Foo & Foo::operator=(const Foo & other)
{
    if(this != &other)
        count = other.count;

    return * this;
}

