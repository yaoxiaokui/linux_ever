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

    void show(){
        cout << ": " << name << endl;
    }

};

//抽象基类Finery
class Finery
{
public:
    virtual void show() = 0;

};

//TShirt类
class TShirt : public Finery
{
public:
    void show(){
        cout << "TShirt ";
    }
};

//Shoes类
class Shoes : public Finery
{
public:   
    void show(){
        cout << "Shoes ";
    }

};

//Suit类
class Suit : public Finery
{
public:
    void show(){
        cout << "Suit ";
    }
};

//Tie类
class Tie : public Finery
{
public:
    void show(){
        cout << "Tie ";
    }
};

//Pants类
class Pants : public Finery
{
public:
    void show(){
        cout << "Pants ";
    }
};

//主程序
int main()
{
    Person p1("张三"); 
    TShirt tshirt;
    Shoes shoes;

    tshirt.show();
    shoes.show();
    p1.show();

    Person p2("李四");
    Suit suit;
    Tie tie;
    Pants pants;

    suit.show();
    tie.show();
    pants.show();
    p2.show();

    return 0;
}
