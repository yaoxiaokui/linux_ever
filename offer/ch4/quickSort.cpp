/*************************************************************************
	> File Name: quickSort.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Jun 2016 08:53:22 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



//快速排序
void quickSort(int data[], int length, int start, int end)
{
    if(start >= end)
        return;

    int value = data[start];//将数组的第一个元素作为基准数字

    int i = start, j = end;

    for(; ;){
        //这两个while循环的执行顺序不能换
        while(data[j] >= value && i < j)
            j--;

        while(data[i] <= value && i < j)
            i++;

        if(i < j)
            swap(data[i], data[j]);
        else
            break;
    }

    data[start] = data[i];//将中间的数字放入第一个位置，是为了将中间的数字作为基准数字
    data[i] = value;//将之前的基准数字放入中间

    quickSort(data, length, start, i-1);
    quickSort(data, length, i+1, end);
}

int main()
{
    int data[] = {2, 3, 5, 7, 9, 1, 4, 3, 8};


    cout << "data: ";
    for(int i = 0; i < 9; ++i)
        cout << data[i] << " ";
    cout << endl;

    quickSort(data, 9, 0, 8);

    cout << "data: ";
    for(int i = 0; i < 9; ++i)
        cout << data[i] << " ";
    cout << endl;


    return 0;
}
