/*************************************************************************
	> File Name: resume.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 Jun 2016 07:39:56 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/***********************************************
*
* 类名称: 简历类
*
**********************************************/
class Resume
{
private:
    string name;
    string sex;
    int age;

public:
    //构造函数
    Resume(){}
    Resume(string nm):name(nm){}

    //设置性别
    void setSex(string sex){
        this->sex = sex;
    }

    //设置年龄
    void setAge(int age){
        this->age = age;
    }

    //显示简历
    void display(){
        cout << "Name: " << name << ", sex: " << sex << ", age: " << age << endl;
    }
};

//客户端进行测试
int main()
{
    //创建三个简历
    Resume resume1("linux_ever");
    resume1.setSex("男");
    resume1.setAge(23);

    Resume resume2("linux_ever");
    resume2.setSex("男");
    resume2.setAge(23);

    Resume resume3("linux_ever");
    resume3.setSex("男");
    resume3.setAge(23);
    

    resume1.display();
    resume2.display();
    resume3.display();


    return 0;
}
