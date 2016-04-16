/*************************************************************************
	> File Name: binarySearch.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月16日 星期六 19时47分10秒
 ************************************************************************/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;


//二分查找
int binarySearch(vector<int> & v, int first, int last, int value)
{
    int half = (first+last)/2;

    if(v[half] == value)
        return half;
    else if(v[half] < value)
        return binarySearch(v, half, last, value);
    else
        return binarySearch(v, 0, half, value);

}


//主函数
int main()
{
    srand(unsigned(time(0)));

    vector<int> v;

    for(int i = 0; i < 10; ++i)
        v.push_back(rand()%10);

    sort(v.begin(), v.end());//排序

    cout << "v: ";
    for(int i = 0; i < 10; ++i)
        cout << v[i] << " ";
    cout << endl;

    int val = v[rand()%10];

    int index = binarySearch(v, 0, v.size()-1, val);
    cout << val << " index is " << index << endl;


    return 0;
}

