/*************************************************************************
	> File Name: more_status.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月04日 星期一 09时40分57秒
 ************************************************************************/

#include <iostream>
using namespace std;


class Parent{
    public:
        Parent(int a = 0){
            this->a = a;
        }
        virtual void print()
        {
            cout << "Parent, a = " << a << endl;
        }
    private:
        int a;
};

class Child:public Parent{
    public:
        Child(int b = 0){
            this->b = b;
        }
        //void print()
        virtual void print()//这里的virtual关键字可以要也可以不要，一般为了表明该函数虚函数则加上该关键字virtual
        {
            cout << "Child, b = " << b << endl;
        }

    private:
        int b;
};

void printObj(Parent & pbase)
{
    pbase.print();
}

int main()
{
    Parent p(10);
    Child c(11);

    printObj(p);
    printObj(c);

    return 0;
}
