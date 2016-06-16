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



//客户端测试
int main()
{
    Stock1 stock1;
    Stock2 stock2;
    Stock3 stock3;
    
    stock1.buy();
    stock2.buy();
    stock3.buy();

    stock1.sell();
    stock2.sell();
    stock3.sell();


    return 0;
}






