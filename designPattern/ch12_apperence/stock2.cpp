/*************************************************************************
	> File Name: stock.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 15 Jun 2016 08:17:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//股票1
class Stock1
{
public:
    void buy(){
        cout << "buy Stock1" << endl;
    }

    void sell(){
        cout << "sell Stock1" << endl;
    }

};

//股票2
class Stock2
{
public:
    void buy(){
        cout << "buy Stock2" << endl;
    }

    void sell(){
        cout << "sell Stock2" << endl;
    }

};

//股票3
class Stock3
{
public:
    void buy(){
        cout << "buy Stock3" << endl;
    }

    void sell(){
        cout << "sell Stock3" << endl;
    }

};


//基金
class Fund
{
private:
    Stock1 stock1;
    Stock2 stock2;
    Stock3 stock3;
public:
    //买入基金
    void buy(){
        stock1.buy();
        stock2.buy();
        stock3.buy();
    }

    //卖出基金
    void sell(){
        stock1.sell();
        stock2.sell();
        stock3.sell();
    }
};


//客户端测试
int main()
{
    Fund fund;

    fund.buy();
    fund.sell();

    return 0;
}






