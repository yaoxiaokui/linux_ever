/*************************************************************************
	> File Name: unique_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Mar 2017 12:42:25 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main()
{
    unique_ptr<double> p1;
    unique_ptr<int> p2(new int(42));

    //cout << "p2 = " << p2 << ", *p2 = " << *p2 << endl;
    cout << "*p2 = " << *p2 << endl;

    unique_ptr<string> p3(new string("p3string"));
    //cout << "p3 = " << p3 << ", *p3 = " << *p3 << endl;
    cout << "*p3 = " << *p3 << endl;

    unique_ptr<string> p4(p3.release());
    cout << "*p4 = " << *p4 << endl;
    //cout << "*p3 = " << *p3 << endl;
    

    unique_ptr<string> p5(new string("p5string"));
    p4.reset(p5.release());
    cout << "*p4 = " << *p4 << endl;


    return 0;
}
