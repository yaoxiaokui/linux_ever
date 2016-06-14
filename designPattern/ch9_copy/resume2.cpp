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
    //拷贝构造
    Resume(const Resume & another){
        *this = another;
    }

    //赋值运算重载函数
    Resume & operator=(const Resume & another){
        name = another.getName();
        sex = another.getSex();
        age = another.getAge();

        return *this;
    }

    //获取名字
    const string & getName() const { 
        return name;
    }
    //获取性别
    const string & getSex() const {
        return sex;
    }

    //获取年龄
    const int getAge() const {
        return age;
    }

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

    //克隆函数
    Resume * clone(){
        return new Resume(*this);
    }
};

//客户端进行测试
int main()
{
    //创建三个简历
    Resume * resume1 = new Resume("linux_ever");
    resume1->setSex("男");
    resume1->setAge(23);


    //直接用简历1来克隆两个简历(不用再调用同样的构造函数实例化两个简历对象)
    Resume * resume2 = resume1->clone();

    Resume * resume3 = resume1->clone();
    resume3->setAge(24);
    

    resume1->display();
    resume2->display();
    resume3->display();


    delete resume1;
    delete resume2;
    delete resume3;

    return 0;
}
