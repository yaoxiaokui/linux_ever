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


int main()
{
    cout << "有虚函数: ";
    cout << "sizeof(Parent) = " << sizeof(Parent) << endl;
    return 0;
}
