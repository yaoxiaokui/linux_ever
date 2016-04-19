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
//递归实现
int binarySearch(vector<int> & v, int first, int last, int value)
{

    if(first > last)//注意该递归函数的跳出判断语句
        return -1;

    //int half = (first+last)/2;
    int half = (last-first)/2 + first;

    if(v[half] == value)
        return half;
    else if(v[half] < value)
        return binarySearch(v, half+1, last, value);
    else if(v[half] > value)
        return binarySearch(v, first, half-1, value);

}

//非递归实现
int binarySearch(vector<int> & v, int value)
{
    int low = 0, high = v.size()-1;

    while(low <= high){
        int mid = (low+high)/2;//(high-low)/2 + low
        //int mid = (high-low)/2 + low;//这个可以防止溢出

        if(v[mid] == value)
            return mid;
        else if(v[mid] > value)
            high = mid-1;
        else
            low = mid+1;
    }

    return -1;
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

    index = binarySearch(v, 0, v.size()-1, 5);
    cout << 5 << " index is " << index << endl;

    index = binarySearch(v, 6);
    cout << 6 << " index is " << index << endl;

    index = binarySearch(v, 100);
    cout << 100 << " index is " << index << endl;



    return 0;
}

