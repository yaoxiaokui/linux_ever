/*************************************************************************
	> File Name: complex.h
	> Author: 
	> Mail: 
	> Created Time: 2016年03月23日 星期三 11时09分59秒
 ************************************************************************/

#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <iostream>
//using namespace std;
using std::ostream;
using std::cout;

class complex{

    private:
        double re, im;

    public:
        complex(double r = 0, double m = 0):re(r), im(m){}
        ~complex(){}
        //复制构造函数
        complex(const complex & c){
            re = c.re;
            im = c.im;
            cout << ",执行了复制构造函数,";
        }
        complex & operator+=(complex a){
            re += a.re;
            im += a.im;
            return *this;
        }

        complex & operator+=(double a){
            re += a;
            return *this;
        }

        friend ostream & operator<<(ostream & os, const complex & c); 

};

ostream & operator<<(ostream & os, const complex & c)
{
    os << "re = " << c.re << ", im =  " << c.im << "\n";
}

complex operator+(complex a, complex b)
{
    return a += b;
}

complex operator+(complex a, double b)
{
    return a += b;
}

complex operator+(double b, complex a)
{
    return a += b;
}


#endif

