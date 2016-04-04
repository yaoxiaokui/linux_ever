#include "iostream"
using namespace std;

class Parent
{
public:
	Parent(int a = 0)
	{
        cout << "Parent()" << endl;
		this->a = a;
	}

	virtual ~Parent()
	{
		cout<<"~Parent()"<<endl;
	}

private:
	int a;
};

class Child : public Parent
{
public:
	Child(int b = 0)
	{
		cout<<"Child()"<<endl;
		this->b = b;
	}
	~Child()
	{
		cout<<"~Child()"<<endl;
	}
private:
	int b ;
};

//在父类中声明虚析构函数的原因
//通过父类指针，把所有的子类析构函数都执行一遍。。。
void howtoDel(Parent *pbase)
{
	delete pbase;
}


int main()
{
	Child *pc1 = new Child();

	howtoDel(pc1);

    cout << "***********************" << endl;

    Parent *pp1 = new Parent;
    howtoDel(pp1);

    return 0;
}
