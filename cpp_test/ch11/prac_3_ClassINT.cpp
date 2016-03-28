/*************************************************************************
	> File Name: prac_3_ClassINT.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月28日 星期一 22时41分28秒
 ************************************************************************/

//定义类INT并使之在行为上完全像int，提示定义：INT::operator int()

#include <iostream>
using std::ostream;
using std::cout;


class INT{
    private:
        int value;

    public:
        INT(int val = 0):value(val){}
        ~INT(){}
        operator int(){return value;}
        INT operator++(int){
            int val = value; 
            value++; 
            return val; 
        }

        INT operator++(){
            value++; 
            return value; 
        }

        INT operator--(int){
            int val = value; 
            value--; 
            return val; 
        }

        INT operator--(){
            value--; 
            return value; 
        }

    friend ostream & operator<<(ostream & os, const INT & val);
};


ostream & operator<<(ostream & os, const INT & val)
{
    os << val.value;
    return os;
}


int main()
{
    INT a(10);//10;
    INT b = 9;
    INT c;
    c = b++;

    cout << "a = " << a << std::endl;
    cout << "b = " << b << std::endl;
    cout << "c = " << c << std::endl;

    INT d = ++c;
    cout << "d = " << d << std::endl;

    return 0;
}

