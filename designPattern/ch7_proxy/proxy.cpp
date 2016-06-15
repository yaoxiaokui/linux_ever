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

//追求者的类
class Persuit
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


//测试主函数
int main()
{
    //创建一个女生对象
    Girl girl("章姐");

    //创建一个追求者对象
    Persuit persuit(&girl);
    
    persuit.giveFlower();
    persuit.giveMilk();
    persuit.giveClothes();


    return 0;
}
