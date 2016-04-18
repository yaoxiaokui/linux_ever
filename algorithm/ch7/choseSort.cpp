/*************************************************************************
	> File Name: quicksort2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月17日 星期日 15时36分03秒
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;


//选择排序
//按数组中的位置来排序
//从第一个位置开始，将最小的元素放入该位置
//再从第二个位置开始，将剩下元素的最小元素放入该位置
//直到最后一个
void sort(vector<int> & v)
{
    int index;
    int min;
    int j;

    for(unsigned i = 0; i < v.size(); ++i){
        min = v[i];
        index = i;

        for(j = i+1; j < v.size(); ++j){
            if(min > v[j]){
                min = v[j];
                index = j;//记录最小的元素
            }
        }
        //v[i] = min;
        min = v[i];
        v[i] = v[index];
        v[index] = min;
    }
}

//插入排序
void insertSort(vector<int> & v)
{
    for(unsigned i = 1; i < v.size(); ++i){

        int temp = v[i];
        unsigned j;

        for(j = i; j > 0 && temp < v[j-1]; --j){
            v[j] = v[j-1];
        }
        v[j] = temp;
    } 
}

//主函数
int main()
{
    srand(unsigned(time(0)));

    vector<int> v;

    for(int i = 0; i < 10; ++i)
        v.push_back(rand()%10);

    cout << "v: ";
    for(int i = 0; i < 10; ++i)
        cout << v[i] << " ";
    cout << endl;

    sort(v);
    //insertSort(v);

    cout << "After sort: ";
    for(int i = 0; i < 10; ++i)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
