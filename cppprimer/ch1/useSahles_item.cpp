/*************************************************************************
	> File Name: useSahles_item.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Mar 2017 02:45:24 PM CST
 ************************************************************************/

#include <iostream>
#include "Sales_item.h"
using namespace std;


int main()
{
    Sales_item item1;
    cin >> item1;
    cout << item1;

    Sales_item item2;
    cin >> item2;
    cout << item2;

    Sales_item item3 = item1;
    cout << "item3: " << item3;

    item3 += item1;
    cout << "item3+=item1 : " << item3;

    Sales_item item4(cin);
    cout << "item4 = " << item4;

    return 0;
}
