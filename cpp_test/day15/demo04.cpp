#include <iostream>
using namespace std;


class Parent
{
public:
	//在父类的构造函数里面，调用虚函数，不会产生多态。。
	//言外之意：不会调用子类的虚函数。。。。
	Parent(int a = 0)
	{
		print(); //定义子类对象的时候，想该print函数调用的是子类的print函数。。结果表明调用的是父类的print函数
		this->a = a;
	}

	//第一个动手脚的地方 编译器应该对这个虚函数特殊处理。。。。
	virtual void print()
	{
		cout<< "Parent." <<endl;
	}
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int b = 0)
	{
		this->b = b;
	}
	virtual void print()
	{
		cout<< "Child."<<endl;
	}
private:
	int b ;
};


int main()
{
	Child c1;

    return 0;
}
