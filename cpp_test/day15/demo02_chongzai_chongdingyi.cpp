#include <cstdlib>
#include <iostream>

using namespace std;

class Parent01
{
public:
	Parent01()
	{
		cout<<"Parent01:printf()..do"<<endl;
	}
public:
	void func()
	{
		cout<<"Parent01:void func()"<<endl;
	}

	void abcd()
	{
		cout<<"Parent01:void func()"<<endl;
	}

	virtual void func(int i)
	{
		cout<<"Parent:void func(int i)"<<endl;
	}

	virtual void func(int i, int j)
	{
		cout<<"Parent:void func(int i, int j)"<<endl;
	}
};


//��д���������
//���������д���ڸ�����������virtual�ؼ���, ���ܲ�����̬��������
//���������д��û�м�virtual�ؼ��֣����൱�����������ض��塣�������������ᷢ����̬������
class Child01 : public Parent01
{

public:

	//ԭ���Ƿ����� ���Ƹ��ǣ��������е�û�к��������ģ��������abcd���Ƹ����ˡ�����
	//�������У��ǲ������ظ���ĺ����ġ�������������ô���ģ�˳�ӡ�������
	void abcd(int a, int b)
	{
		cout<<"Parent01:void func()"<<endl;
	}

	//�˴�2��������������func������ʲô��ϵ
	 void func(int i, int j)
	{
		cout<<"Child:void func(int i, int j)"<<" "<<i + j<<endl;
	}

	//�˴�3�������ģ�������func������ʲô��ϵ
	void func(int i, int j, int k)
	{
		cout<<"Child:void func(int i, int j, int k)"<<" "<<i + j + k<<endl;
	}
};

void run01(Parent01* p)
{
	p->func(1, 2);
}

int main()
{
    /*
	Parent01 p;

	p.func();
	p.func(1);
	p.func(1, 2);
    */


	Child01 c;
	//c.Parent01::abcd(); //��������ǴӸ����м̳ж��� ����ʹ�á�����
	//����͸�������ͬ�����֣��������ֻ����Ǻ������ֵ�ʱ���������ָ��Ǹ������֣������ʹ�ø������Դ����Ҫ��::��
	//c.Parent01::func(); //����1 ��������ǴӸ����м̳ж�����Ϊʲô����ط�����ʹ��
    c.Parent01::func(); //����1
	//c.func(1, 2);
		/*
	run01(&p);
	run01(&c);
	*/
	return 0;
}

//����1��child����̳и�������func��������仰��������why
//c.func(); 

//1���������func�޷����ظ��������func 
//2���������������ͬ�ĺ����������������֣��������Ƹ���
//3//c.Parent::func();
//����2 ���������func�͸����������func������ʲô��ϵ��

