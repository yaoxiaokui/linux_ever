#include <iostream>
using namespace std;


class Parent
{
public:
	//�ڸ���Ĺ��캯�����棬�����麯�������������̬����
	//����֮�⣺�������������麯����������
	Parent(int a = 0)
	{
		print(); //������������ʱ�����print�������õ��������print������������������õ��Ǹ����print����
		this->a = a;
	}

	//��һ�����ֽŵĵط� ������Ӧ�ö�����麯�����⴦��������
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
