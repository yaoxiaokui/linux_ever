/*************************************************************************
	> File Name: Person.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Jun 2016 08:21:53 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


//Person类
class Person
{
private:
    string name;
public:

    Person(string nm):name(nm){

    }

    void WearTShirt(){
        cout << "TShirt ";
    }

    void WearShoes(){
        cout << "Shoes ";
    }

    void WearSuit(){
        cout << "Suit ";
    }

    void WearTie(){
        cout << "Tie ";
    }

    void show(){
        cout << ": " << name << endl;
    }

};

//主程序
int main()
{
    Person p1("张三"); 
    p1.WearTShirt();
    p1.WearShoes();
    p1.show();

    Person p2("李四");
    p2.WearSuit();
    p2.WearTie();
    p2.show();
    

    return 0;
}
