/*************************************************************************
	> File Name: operatorAdd.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Apr 2017 10:22:11 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Int{

    friend ostream & operator<<(ostream & os, const Int & i){
        os << i.num;
        return os;
    }
public:
    Int(int i):num(i){}
    Int(){num = 0;}

    Int & operator++(){
        ++num;
        return *this;
    }

    Int & operator--(){
        --num;
        return *this;
    }


    Int operator++(int){
        Int temp = *this;
        ++*this;
        return temp;
    }

    Int operator--(int){
        Int temp = *this;
        --*this;
        return temp;
    }

private:
    int num;

};


int main()
{
    Int i1(1);
    cout << "i1 = " << i1 << endl;

    ++i1;
    cout << "++i1 = " << i1 << endl;
    
    --i1;
    cout << "--i1 = " << i1 << endl;

    cout << "i1++ = " << i1++ << ", i1 = " << i1 << endl;
    cout << "i1-- = " << i1-- << ", i1 = " << i1 << endl;

    return 0;
}
