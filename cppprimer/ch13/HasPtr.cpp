/*************************************************************************
	> File Name: HasPtr.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 31 Mar 2017 03:33:31 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


class HasPtr{

public:
    HasPtr();
    HasPtr(const string & str);
    HasPtr(const HasPtr & other);
    HasPtr & operator=(const HasPtr & other);
    ~HasPtr(){
        if(ptr)
            delete ptr;
    }
private:
    string *ptr;
    int id;

friend ostream & operator<<(ostream & os, const HasPtr & hasPtr);
};

ostream & operator<<(ostream & os, const HasPtr & hasPtr)
{
    os << *hasPtr.ptr << ", id = " << hasPtr.id;
}

HasPtr::HasPtr()
{
    ptr = new string;
    id = 0;
}

HasPtr::HasPtr(const string & str)
{
    ptr = new string(str);
    id = 0;
}

HasPtr::HasPtr(const HasPtr & other)
{
    ptr = new string(*other.ptr);
    id = other.id;
}

HasPtr & HasPtr::operator=(const HasPtr & other)
{
    if(this == &other)
        return *this;

    if(ptr != NULL){
        delete ptr;
    }

    ptr = new string(*other.ptr);
    id = other.id;
}


int main()
{
    HasPtr p1;
    cout << p1 << endl;

    HasPtr p2("p2");
    cout << p2 << endl;
    
    HasPtr p3;
    cout << p3 << endl;

    p3 = p2;
    cout << p3 << endl;

    return 0;
}
