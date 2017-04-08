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
        if(--*use == 0){
            delete ptr;
            delete use;
        }
    }
private:
    string *ptr;
    int id;
    int * use;

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
    use = new int(1);
}

HasPtr::HasPtr(const string & str)
{
    ptr = new string(str);
    id = 0;
    use = new int(1);
}

HasPtr::HasPtr(const HasPtr & other)
{
    ptr = new string(*other.ptr);
    id = other.id;
    use = other.use;
    ++*use;
}

HasPtr & HasPtr::operator=(const HasPtr & other)
{
    if(this == &other)
        return *this;

    ++*other.use;

    if(--*use == 0){
        delete ptr;
        delete use;
    }

    ptr = other.ptr;
    id = other.id;
    use = other.use;
    return *this;
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
