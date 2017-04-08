/*************************************************************************
	> File Name: 24oneCount.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 31 Aug 2016 02:03:12 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//解法1
int numOfone(int num)
{
    int count = 0;
    while(num){
        if(num % 10 == 1){
            count++;
        }
        num /= 10;
    }
    return count;
}

int sumOfone(int num)
{
    int count = 0;
    for(int i = 1; i <= num; ++i){
        count += numOfone(i);
    }

    return count;
}

//主函数
int main()
{
    int N;
    cout << "input the N:";
    cin >> N;

    cout << "sum count of one = " << sumOfone(N) << endl;

    return 0;
}
