/*************************************************************************
	> File Name: newdelete.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Apr 2017 03:14:15 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;



class Test{

private:
    int num;
    int num2;

public:
    Test(){
        num = 0;
        cout << "Test(), num = " << num << endl;
    }

    Test(int n){
        num = n;
        cout << "Test(), num = " << num << endl;
    }

    ~Test(){
        cout << "~Test(), num = " << num << endl;
    }

    void * operator new(size_t size);
    void operator delete(void * p);
};

void * Test::operator new(size_t size)
{
    cout << "operator new " << ", size = " << size << endl;
    return ::operator new(size);
}

void Test::operator delete(void * p)
{
    cout << "operator delete" << endl;
    ::operator delete(p);
}

int main()
{
    Test t0;
    Test t1(1);

    Test * pt2 = new Test(2);
    delete pt2;


    return 0;
}
