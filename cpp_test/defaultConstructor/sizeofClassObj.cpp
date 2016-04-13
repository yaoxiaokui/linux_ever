/*************************************************************************
	> File Name: sizeofClassObj.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月12日 星期二 21时31分43秒
 ************************************************************************/

#include <iostream>
using namespace std;


class X{};
class Y : public virtual X{};
class Z : public virtual X{};
class A : public Y, public Z{};

class W : public X{};

int main()
{
    X x;
    Y y;
    Z z;
    A a;

    cout << "sizeof(X) = " << sizeof(x) << endl;
    cout << "sizeof(y) = " << sizeof(y) << endl;
    cout << "sizeof(z) = " << sizeof(z) << endl;
    cout << "sizeof(a) = " << sizeof(a) << endl;

    W w;
    cout << "sizeof(w) = " << sizeof(w) << endl;

    return 0;
}
