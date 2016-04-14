/*************************************************************************
	> File Name: dataMemberLayout.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月13日 星期三 19时21分01秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

class X{

    public:
        X(){}
        X(int val, int v2):x(val), z(v2){}
        virtual void print(){cout << x << endl;}
        //void print(){}
    //private:
    public:
        int x;
        int z;

};

class Point:public X{

    public:
        ///Point(int v1, int v2):X(v1), y(v2){}
        Point(int a, int b, int v2):X(a, b), y(v2){}
        virtual void print(){
         //   cout << "address = " << p << ", ";
            cout << y << endl;}
            
    private:
        int y;
        //char * p = (char*)&y;
};


class B{
    public:
        B(int v1, int v2):a(v1), b(v2){}
        void print(){cout << a << " " << b << endl;}
    private:
        int a;
        int b;
};

int main()
{
    X x(3, 1234);
    //Point p(1, 2);

    //X x;
    Point p(2, 3, 4);
    cout << "sizeof(x) = " << sizeof(x) << endl;
    cout << "sizeof(p) = " << sizeof(p) << endl;

    int * px = (int *)&x;
    cout << "px = " << px << endl;
    cout << "px + 1 = " << px + 1 << endl;
    cout << *(px + 2) << endl;
    cout << *(px + 3) << endl;

    printf("&X::x = %p\n", &X::x);
    printf("&X::z = %p\n", &X::z);

    int * pp = (int *)&p;
    cout << *(pp + 2) << endl;
    cout << *(pp + 3) << endl;
    cout << *(pp + 4) << endl;
    
    //x.print();
    //p.print();

    cout << "*******************************" << endl;
    //B y(1, 2);
    //y.print();
    //cout << "sizeof(y) = " << sizeof(y) << endl;

    return 0;
}
