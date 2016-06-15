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
    Person(){}
    Person(string nm):name(nm){

    }

    virtual void show(){
        cout << ": " << name << endl;
    }

};

//类Finery
class Finery : public Person
{
protected:
    Person * component;
public:
    void Decorate(Person * component){
        this->component = component;
    }

    void show(){
        component->show();
    }

};

//TShirt类
class TShirt : public Finery
{
public:
    void show(){
        cout << "TShirt ";
        Finery::show();
    }
};

//Shoes类
class Shoes : public Finery
{
public:   
    void show(){
        cout << "Shoes ";
        Finery::show();
    }

};

//Suit类
class Suit : public Finery
{
public:
    void show(){
        cout << "Suit ";
        Finery::show();
    }
};

//Tie类
class Tie : public Finery
{
public:
    void show(){
        cout << "Tie ";
        Finery::show();
    }
};

//Pants类
class Pants : public Finery
{
public:
    void show(){
        cout << "Pants ";
        Finery::show();
    }
};

//主程序
int main()
{
    Person p1("张三"); 
    TShirt tshirt;
    Shoes shoes;

    tshirt.Decorate(&p1);
    shoes.Decorate(&tshirt);
    shoes.show();

    Person p2("李四");
    Suit suit;
    Tie tie;
    Pants pants;

    suit.Decorate(&p2);
    tie.Decorate(&suit);
    pants.Decorate(&tie);
    pants.show();


    return 0;
}
