/*************************************************************************
	> File Name: coins.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Aug 2016 09:23:18 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int getCount(int value)
{
    //if(value < 3)
        //return value;
    if(value == 2)
        return 1;
    else if(value >= 3 && value < 5)
        return 1+getCount(value-3);
    else if(value >= 5)
        return 1+getCount(value-5);
}


int getCount(vector<int> &v, int value)
{
    vector<int> counts;

    for(int i = 0; i <= value; ++i){
        counts.push_back(0);
    }


    for(int i = 1; i <= value; ++i){

        int min = 0x7FFFFF;
        for(int j = 0; j < v.size(); ++j){
            if(i - v[j] >= 0){
                if(min > counts[i-v[j]])
                    min = counts[i-v[j]];
            }
        }
        counts[i] = min + 1;
    }


    return counts[value];
}


int main()
{
    //cout << "输入3种硬币的价值: ";
    //int c1, c2, c3;

    //cin >> c1 >> c2 >> c3;

    cout << "输入总的价值: ";
    int value;
    cin >> value;

  
    vector<int> v;
    int num;
    while(cin >> num)
    {
        v.push_back(num);
    }


    cout << "最少需要" << getCount(value) << "个硬币" << endl;


    cout << "最少需要" << getCount(v, value) << "个硬币" << endl;

    return 0;
}
