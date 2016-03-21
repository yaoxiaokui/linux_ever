/*************************************************************************
	> File Name: visit_private_data.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月21日 星期一 20时10分37秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class People{

    private:
        int num;
        int age;
        int hight;
        string name;
    public:
        People(){}
        People(int n, int a, int h, string na):num(n), age(a), hight(h), name(na){}
        ~People(){}

        int get_num(){return num;}
        int get_age(){return age;}
        int get_hight(){return hight;}
        string get_name(){return name;}
        
        void set_num(int val){num = val;}
        void set_age(int val){age = val;}
        void set_hight(int val){hight = val;}
        void set_name(string val){name = val;} 
};

int main()
{
    People p1(1, 22, 170, "linux");
    cout << "p1.num = " << p1.get_num() << endl;
    cout << "p1.age= " << p1.get_age() << endl;
    cout << "p1.hight = " << p1.get_hight() << endl;

    cout << "用地址访问类的私有成员变量: " << endl;
    int* p = (int*)&p1;
    cout << "*p = " << *p << endl;
    cout << "*(p+1) = " << *(p+1) << endl;
    cout << "*(p+2) = " << *(p+2) << endl;
    
    *p = 11;
    cout << "after *p = 11, *p = " << *p << endl;

    cout << "用地址输出类对象的前20个字节的值: " << endl;
    char* ptr = (char*)&p1;

    for(int i = 0; i < 20; ++i){
        cout << "*(ptr+" << i << ") = " << *(ptr+i) << endl;
    }


    return 0;
}
