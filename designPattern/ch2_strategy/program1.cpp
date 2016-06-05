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

    cout << "单价: ";
    cin >> price;
    cout << "数量: ";
    cin >> num;

    totalPrice = price * num;

    cout << "总计: " << totalPrice << endl;


    return 0;
}
