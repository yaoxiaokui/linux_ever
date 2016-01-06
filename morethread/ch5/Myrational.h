/*************************************************************************
	> File Name: Myrational.h
	> Author: 
	> Mail: 
	> Created Time: 2015年11月13日 星期五 10时01分46秒
 ************************************************************************/

#ifndef _MYRATIONAL_H
#define _MYRATIONAL_H
#include <iostream>

class MyRational{
public:
    MyRational(int x, int y):my_x(x), my_y(y){}

    friend std::ostream & operator<<(std::ostream &os, const MyRational & m) const{
        os << m.my_x << ", " << m.my_y << std::endl; 
        return os;
    }    
    MyRational operator+(const MyRational &m1, const MyRational &m2){
        return MyRational(m1.my_x+m2.my_x, m2.my_y+m2.my_y);
    }
private:
    int my_x;
    int my_y;
};

#endif
