/*************************************************************************
	> File Name: money.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月23日 星期一 16时54分34秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

int coin_num[6];
int money;

void input_data()
{
    cout << "C1 = ";
    cin >>  coin_num[0];
    cout << "C5: ";
    cin >> coin_num[1];
    cout << "C10: ";
    cin >> coin_num[2];
    cout << "C50: ";
    cin >> coin_num[3];
    cout << "C100: ";
    cin >> coin_num[4];
    cout << "C500: ";
    cin >> coin_num[5];
    cout << "money: ";
    cin >> money;
}

void solve()
{
    int min_coin_num = 0;
    int paid_money = 0;
    int coin_values[6] ={1, 5, 10, 50, 100, 500};

    for (int i = 5; i >=0; --i){
        int min_num = min(money/coin_values[i], coin_num[i]);
        if(min_num != 0){
            cout << coin_values[i] << " used " << min_num << endl;
        }
        money -= min_num*coin_values[i];
        min_coin_num += min_num;
    }
    cout << "min_coin_num is " << min_coin_num << endl;
}

int main()
{

    input_data();

    solve();

    exit(0);
}
