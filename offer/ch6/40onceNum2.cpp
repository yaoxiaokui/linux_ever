/*************************************************************************
	> File Name: 40onceNum.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Jul 2016 10:10:35 AM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

//求的数字num第一个为1的位
int findFirstBitIs1(int num)
{
    int index = 0;

    //注意while里面的括号
    while(((num & 1) == 0) && (index < 8*sizeof(int))){
        num = num >> 1;
        ++index;
    }
    
    return index;
}

//判断数字num的第index位是否为1
bool isBit1(int num, int index)
{
    num = num >> index;
    return (num & 1);
}


//先对数组中所有元素求异或，
//然后找到异或结果的第一个是1的位的位置index(从低位开始计算)
//根据数组中所有元素的index位是否为1，将数组分为两个子数组
//分别对两个子数组的元素求异或，每个子数组异或的结果就是出现一次的元素

void findNumAppearOnce(vector<int> & v, int length, int *num1, int * num2)
{
    if(v.size() <=2)
        return;

    int resultExclusiveOR = 0;
    for(int i = 0; i < length; ++i){
        resultExclusiveOR ^= v[i];
    }

    //求得resultExclusiveOR中第一个是1的位的位置
    int index = findFirstBitIs1(resultExclusiveOR);

    *num1 = 0;
    *num2 = 0;

    for(int i = 0; i < length; ++i){
        if(isBit1(v[i], index))
            *num1 ^= v[i];
        else
            *num2 ^= v[i];
    }
}


//主测试函数
int main()
{
    vector<int> v;
    int value;

    while(cin >> value){
        v.push_back(value); 
    }

    cout << "v: ";
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;

    int num1, num2;
    findNumAppearOnce(v, v.size(), &num1, &num2);
    cout << num1 << " " << num2 << endl;


    return 0;
}
