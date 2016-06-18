/*************************************************************************
	> File Name: SigleInstance.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Jun 2016 06:44:44 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


//只能生成一个类对象的类
class SigleInstance
{
public:
    //指向类的一个实例对象
    static SigleInstance * instance;
private:
    //私有的构造函数
    SigleInstance(){cout << "执行SigleInstance 构造函数" << endl;}
public:
    //创建一个实例对象
    static SigleInstance * getSigleInstance(){
        if(instance == NULL)
            instance = new SigleInstance();

        return instance;
    }
};


//初始化静态成员变量
SigleInstance * SigleInstance::instance = NULL;

//测试函数
int main()
{

    SigleInstance * SigleInstance1 = SigleInstance::getSigleInstance();
    SigleInstance * SigleInstance2 = SigleInstance::getSigleInstance();
    SigleInstance * SigleInstance3 = SigleInstance::getSigleInstance();


    if(SigleInstance1 == SigleInstance2){
        cout << "SigleInstance1 == SigleInstance2" << endl;
    }

    if(SigleInstance1 == SigleInstance3){
        cout << "SigleInstance1 == SigleInstance3" << endl;
    }

    return 0;
}
