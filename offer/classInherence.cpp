/*************************************************************************
	> File Name: classInherence.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Aug 2016 02:12:40 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A
{

    char k[3];
public:
    virtual void aa(){}
};


//class B : public virtual A
class B : public A
{
    char j[3];

public:
    virtual void bb(){}

};

class C : public virtual B
{
    char i[3];
public:
    virtual void cc(){}
};

int main()
{
    cout << "sizeof A = " << sizeof(A) << endl;
    cout << "sizeof B = " << sizeof(B) << endl;
    cout << "sizeof C = " << sizeof(C) << endl;
    
    return 0;
}
