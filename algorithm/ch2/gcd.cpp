/*************************************************************************
	> File Name: gcd.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月06日 星期三 15时04分53秒
 ************************************************************************/
#include <iostream>
using namespace std;

//g(a,b) = gcd(b,r)

int gcd(int a, int b)
{
    int r = 0;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int x, y;
    cout << "输入两个数字：";
    cin >> x >> y;
    cout << "这两个数字的最大公因数是：";
    cout << gcd(x, y) << endl;

    return 0;
}
