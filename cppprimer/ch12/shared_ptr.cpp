/*************************************************************************
	> File Name: shared_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Mar 2017 04:14:30 PM CST
 ************************************************************************/

#include <iostream>
#include <memory>
#include <string>

using namespace std;


int main()
{
    shared_ptr<string> p1(new string);


    if(p1 && p1->empty()){
        *p1 = "Hi";
    }

    cout << p1 << endl;
    cout << *p1 << endl;

    cout << "get: " << endl;

    int *p = new int(10);
    shared_ptr<int> a(p);

    if(a.get() == p)
        cout << "a.get() == p" << endl;

    cout << *a.get() << endl;
    cout << *a << endl;
    cout << *p << endl;


    shared_ptr<int> foo;
    shared_ptr<int> bar(new int);

    cout << "foo unique? " << endl;
    cout << "1: " << foo.unique() << endl;
    cout << "foo.use_count" << foo.use_count() << endl;

    foo = bar;
    cout << "2: " << foo.unique() << endl;
    cout << "foo.use_count" << foo.use_count() << endl;


    bar = nullptr;
    cout << "3: " << foo.unique() << endl;
    cout << "foo.use_count" << foo.use_count() << endl;
    return 0;
}
