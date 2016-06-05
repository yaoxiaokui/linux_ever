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
    Cost(){}
    virtual float getCost(float totalPrice){}
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
* 功能:该类是满减类
**************************************/
class CostFactory
{
public:
    static Cost * createCost(int choice){
        switch (choice){
            case 1:
                return new CostNormal();//不打折
            case 2:
                return new CostDiscout(0.8);//打折为0.8折
            case 3:
                return new CostReturn(199, 100);//满199-100
            default:
                return NULL;
        }
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

    cout << "单价: ";
    cin >> price;
    cout << "数量: ";
    cin >> num;


    //由于是字符界面，所以比较麻烦
    //如果是图像界面的话，就比较方便

    cout << "无折扣(1), 有折扣(2), 有满减(3): ";
    cin >> choice;

    cout << "-------------------------------" << endl;
    totalPrice = price * num;
    cout << "原价: " << totalPrice << endl;

    Cost * cost = CostFactory::createCost(choice);

    totalPrice = cost->getCost(totalPrice);
    cout << "总计: " << totalPrice << endl;


    return 0;
}
