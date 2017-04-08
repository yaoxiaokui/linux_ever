/*************************************************************************
	> File Name: minMax.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Aug 2016 10:10:12 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int fun(vector<int> & v, int & min, int & max)
{
    map<int, int> subValue;
    int len = v.size();
    int value = 0;

    for(int i = 0; i < len; ++i){
        for(int j = i+1;j < len; ++j){
            value = v[i] - v[j];
            subValue[value]++;
        }
    }

    map<int, int>::iterator minIt = subValue.begin();
    min = minIt->second;

    map<int, int>::reverse_iterator maxIt = subValue.rbegin();
    max = maxIt->second;
}

void fun2(vector<int> & v, int & min, int & max)
{
    int maxValue = -1;
    int minValue = 0x7FFFFFFF;
    int maxNum = 0;
    int minNum = 0;
    int len = v.size();
    int midValue = -1;
    int midNum = 0;

    for(int i = 0; i < len; ++i){
        //求最大值和最大值的个数
        if(v[i] > maxValue){
            maxValue = v[i];
            maxNum = 1;
        }
        else if(v[i] == maxValue){
            maxNum++;
        }

        //求最小值和最小值的个数
        if(v[i] < minValue){
            minValue = v[i];
            minNum = 1;
        }
        else if(v[i] == minValue){
            minNum++;
        }
    }

    //求次大数和次大数的个数

    cout << "minValue = " << minValue << ", minNum = " << minNum << endl;
    cout << "maxValue = " << maxValue << ", maxNum = " << maxNum << endl;

}

int main()
{
    int num;
    int value;
    while(cin >> num){
        
        vector<int> v;

        //输入数据 
        for(int i = 0; i < num; ++i){
            cin >> value;
            v.push_back(value);
        }

        int min = 0;
        int max = 0;

        //cout << fun(v, min, max) << endl;
        fun2(v, min, max);
        cout << "min = " << min << ", max = " << max << endl;


    }



    return 0;
}

