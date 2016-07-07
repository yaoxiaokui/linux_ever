/*************************************************************************
	> File Name: 42findSequenceOfSum.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Jul 2016 09:15:27 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//打印序列
void printSequence(int small, int big)
{
    for(int i = small; i <= big; ++i)
        cout << i << " ";
    cout << endl;
}

//求和为sum的所有连续序列
//比下面的函数优点在于不用每次都对序列进行求和
void findSequenceOfSum2(int sum)
{
    int small = 1;
    int big = 2;
    int currentSum = small + big;
    int middle = (1+sum)/2;

    while(small < middle){

        //如果序列和等于sum，则输出
        //如果序列和小于sum，则增大big的值
        //如果序列和大于sum，则增大small的值
        if(currentSum == sum){
            printSequence(small, big);
            ++big;//当等于sum的时候，一定要++big，进入到下一步，否则会死循环
            currentSum += big;
        }
        else if(currentSum < sum){
            ++big;
            currentSum += big;
        }
        else{
            currentSum -= small;
            ++small;
        }
    }
}


//求和为sum的所有连续序列
void findSequenceOfSum(int sum)
{
    int small = 1;
    int big = 2;

    while(small < (1+sum)/2){
        //对当前序列进行求和
        int total = 0;
        for(int i = small; i <= big; ++i){
            total += i;
        }
        //如果序列和等于sum，则输出
        //如果序列和小于sum，则增大big的值
        //如果序列和大于sum，则增大small的值
        if(total == sum){
            printSequence(small, big);
            ++big;//当等于sum的时候，一定要++big，进入到下一步，否则会死循环
        }
        else if(total < sum)
            ++big;
        else 
            ++small;
    }
}



//主测试函数
int main()
{
    int sum = 0;
    cout << "输入和: ";
    cin >> sum;

    findSequenceOfSum(sum);

    cout << "-----------------------------" << endl;

    findSequenceOfSum2(sum);


    return 0;
}


