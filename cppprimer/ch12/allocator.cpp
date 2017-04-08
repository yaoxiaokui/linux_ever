/*************************************************************************
	> File Name: allocator.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Mar 2017 07:38:47 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main()
{
    const int n = 10;
    allocator<string> alloc;
    auto const p = alloc.allocate(n);

    auto q = p;
    alloc.construct(q++, 3, 'a');
    //cout << "*q = " << *q << endl;
    cout << "*p = " << *p << endl;

    alloc.construct(q++, 10, 'c');
    //cout << "*q = " << *q << endl;
    cout << "*p = " << *p << endl;

    alloc.construct(q++, "hi");
    //cout << "*q = " << *q << endl;
    cout << "*p = " << *p << endl;
    cout << "*p+1 = " << *(p+1) << endl;


    return 0;
}
