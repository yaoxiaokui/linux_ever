/*************************************************************************
	> File Name: proxy.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 11 Jun 2016 08:29:05 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//女孩的类
class Girl
{
private:
    string name;
public:
    Girl(){}
    Girl(string nm):name(nm){}

    string getName(){
        return name;
    }

};

//代理的类
class Proxy 
{
private:
    Girl * girl;
public:

    Proxy(){}
    Proxy(Girl * pGirl):girl(pGirl){}

    //送花
    void giveFlower(){
        cout << "give " << girl->getName() << " flower" << endl;
    }

    //送牛奶
    void giveMilk(){
        cout << "give " << girl->getName() << " milk" << endl;
    }

    //送衣服
    void giveClothes(){
        cout << "give " << girl->getName() << " clothes" << endl;
    }

};


//测试主函数
int main()
{
    //创建一个女生对象
    Girl girl("章姐");

    //创建一个代理对象
    Proxy proxy(&girl);
    
    proxy.giveFlower();
    proxy.giveMilk();
    proxy.giveClothes();


    return 0;
}
