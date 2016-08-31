/*************************************************************************
	> File Name: 21numOfone.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 31 Aug 2016 11:08:59 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//解法1
int numOfOne(int num)
{
    int count = 0;
    while(num){
        count++;
        num = num &(num-1);
    }

    return count;
}

//解法2
int numOfOne2(int num)
{
    int count = 0;
    while(num){
        count += num%2;
        num /= 2;
    }
    
    return count;
}

//解法3 
int numOfOne3(int num)
{
    int count = 0;
    while(num){
        count += num & 0x1;
        num >>= 1;
    }
    return count;
}

//主函数
int main()
{
    int num;

    cout << "输入一个数字: ";
    cin >> num;

    cout << numOfOne(num) << endl;
    cout << numOfOne2(num) << endl;
    cout << numOfOne3(num) << endl;


    return 0;
}
