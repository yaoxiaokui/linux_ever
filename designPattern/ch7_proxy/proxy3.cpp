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

//追求者和代理类的基类
class GiveGifts
{
public:
    virtual void giveFlower() = 0;
    virtual void giveMilk() = 0;
    virtual void giveClothes() = 0;
};

//追求者的类
class Persuit : public GiveGifts
{
private:
    Girl * girl;
public:

    Persuit(){}
    Persuit(Girl * pGirl):girl(pGirl){}

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


//代理的类
class Proxy : public GiveGifts
{
private:
    Persuit * persuit;

public:
    //构造函数
    Proxy(){
        persuit = NULL;
    }

    //构造函数
    //通过代理将追求者和女生关联起来
    Proxy(Girl * girl){
        persuit = new Persuit(girl);
    }

    //析构函数
    ~Proxy(){
        if(persuit)
            delete persuit;
    }

    //送花
    void giveFlower(){
        persuit->giveFlower();
    }

    //送牛奶
    void giveMilk(){
        persuit->giveMilk();
    }

    //送衣服
    void giveClothes(){
        persuit->giveClothes();
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
