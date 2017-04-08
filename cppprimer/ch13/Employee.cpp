/*************************************************************************
	> File Name: Employee.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 31 Mar 2017 03:19:38 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


class Employee{

public:
    static int ID;
private:
    string name;
    int id;
public:
    Employee(){id = ++ID;}
    Employee(string nm){
        name = nm;
        id = ++ID; 
    }

friend ostream & operator<<(ostream & os, const Employee & employee);
};

ostream & operator<<(ostream & os, const Employee & employee)
{
    os << "ID: " << employee.id << ", name: " << employee.name;
}


int Employee::ID = 0;


int main()
{
    Employee e1;
    cout << e1 << endl;

    Employee e2("e2");
    cout << e2 << endl;

    Employee e3("e3");
    cout << e3 << endl;

    Employee e4;
    cout << e4 << endl;

    

    return 0;
}
