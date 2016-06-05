/*************************************************************************
	> File Name: program1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 05 Jun 2016 05:15:38 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


int main()
{
    int num;
    float price;
    float totalPrice;
    float discount = 1.0;

    cout << "单价: ";
    cin >> price;
    cout << "数量: ";
    cin >> num;

    cout << "折扣(1, 0.8, 0.7, 0.5):";
    cin >> discount;

    totalPrice = price * num;

    cout << "-------------------------------" << endl;
    cout << "原价: " << totalPrice << endl;
    cout << "折扣: " << discount << endl;
    totalPrice = totalPrice * discount;

    cout << "总计: " << totalPrice << endl;


    return 0;
}
