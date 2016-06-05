/*************************************************************************
	> File Name: program1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 05 Jun 2016 05:15:38 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

/**************************************
* 功能:该类是收费的基类
**************************************/
class Cost
{
public:
    virtual float getCost(float totalPrice) = 0;//纯虚函数，该类是抽象类
};

/**************************************
* 功能:该类是正常收费类(不打折)
**************************************/
class CostNormal : public Cost
{
public:
    float getCost(float totalPrice){
        return totalPrice;
    }
};

/**************************************
* 功能:该类是打折
**************************************/
class CostDiscout : public Cost
{
private:
    float discount;
public:
    CostDiscout(float discnt):discount(discnt){}
    CostDiscout(){}

    float getCost(float totalPrice){
        return totalPrice * discount;
    }
};


/**************************************
* 功能:该类是满减类
**************************************/
class CostReturn : public Cost
{
private:
    float moneyCondition;
    float moneyReturn;
public:
    CostReturn(float mc, float mr):moneyCondition(mc), moneyReturn(mr){}
    CostReturn(){}

    float getCost(float totalPrice){
        if(totalPrice < moneyCondition){
            return totalPrice;
        }
        else{
            totalPrice -= moneyReturn;
            return totalPrice;
        }
    }
};


/**************************************
* 功能:该类用具体的算法类来进行配置
**************************************/
class CostContent
{
private:
    Cost * cost;

public:
    CostContent(Cost * super):cost(super){}

    float getCost(double totalPrice){
        return cost->getCost(totalPrice);
    }

};


/**************************************
* 功能:主函数
**************************************/
int main()
{
    int num;
    float price;
    float totalPrice;
    int choice;

    CostContent * cc = NULL;

    cout << "单价: ";
    cin >> price;
    cout << "数量: ";
    cin >> num;


    //由于是字符界面，所以比较麻烦
    //如果是图像界面的话，就比较方便

    cout << "无折扣(1), 有折扣(2), 有满减(3): ";
    cin >> choice;

    totalPrice = price * num;

    cout << "-------------------------------" << endl;
    cout << "原价: " << totalPrice << endl;

    switch (choice){
        case 1:
            cc = new CostContent(new CostNormal());
            break;
        case 2:
            cc = new CostContent(new CostDiscout(0.8));
            break;
        case 3:
            cc = new CostContent(new CostReturn(199, 100));
            break;
        default:
            cout << "请出入正确的选择" << endl;
            break;
    }

    totalPrice = cc->getCost(totalPrice);

    cout << "总计: " << totalPrice << endl;


    return 0;
}
