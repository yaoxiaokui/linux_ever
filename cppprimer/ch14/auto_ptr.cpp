/*************************************************************************
	> File Name: auto_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Apr 2017 10:10:12 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class A{

private:
    int a;
public:
    A(){
        cout << "A()" << endl;
    }

    ~A(){
        cout << "~A()" << endl;
    }

    void fun(){
        cout << "fun()" << endl;
    }
};


template<typename T>
class MyAuto_ptr{
private:
    T * ptr;
public:
    MyAuto_ptr(T * rhs):ptr(rhs){}
    T * operator->(){
       return ptr; 
    }

    T & operator*(){
        return *ptr;
    }

    ~MyAuto_ptr(){
        delete ptr;
    }
};


int main()
{
    MyAuto_ptr<A> ptr(new A());
    ptr->fun();

    (*ptr).fun();

    

    return 0;
}
