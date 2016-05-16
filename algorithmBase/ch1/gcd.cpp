/*************************************************************************
	> File Name: gcd.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 May 2016 07:07:52 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//方法1：该方法是欧几里得算法
//求m,n的最大公约数
//gcd(m, n) = gcd(n, m%n) = ... = gcd(m, 0); ----> return m;
int gcd(int m, int n)
{
    if(n == 0)
        return m;
    else if(m == 0){
        return n;
    }

    /*
    int t = n;
    n = m % n;
    m = t;
    */

    gcd(n, m%n);
}

//方法2:该方法是连续整数检测算法
int gcd2(int m, int n)
{
    if(n == 0)
        return m;
    else if(m == 0)
        return n;
    
    int min = 0;
    if(m > n)
        min = n;
    else
        min = m;

    //min是两个数字的较小者
    for(int i = min; i > 0; --i){
        if((m % i == 0) && (n % i == 0))
            return i;
    }
}

int main()
{

    cout << "输入两个数字，求该两个数字的最大公约数: ";
    int m, n;
    cin >> m >> n;

    //m, n是两个不全为0,并且非负整数
    cout << m << ", " << n << " :的最大公约数为: ";
    cout << gcd(m, n) << endl;
    cout << "方法2: gcd(m, n) = " << gcd2(m, n) << endl;



    return 0;
}
