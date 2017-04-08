/*************************************************************************
	> File Name: selectionSort.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Jul 2016 03:15:10 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

//选择排序
void selectionSort(int arr[], int num)
{
    int minIndex = 0;

    for(int i = 0; i < num-1; ++i){
        //i是未排序数组中第一个元素的下标,第一次为0
        minIndex = i;

        //minIndex是未排序数组中最小元素的下标
        for(int j = i+1; j < num; ++j){
            if(arr[minIndex] > arr[j])
                minIndex = j;
        }
        //将未排序数组中第一个元素和最小元素进行互换
        swap(arr[minIndex], arr[i]);
        //下一个循环会++i，也就是将已经排序数组的元素个数加1
    }

}


//打印数组信息
void print(int arr[], int num)
{
    for(int i = 0; i < num; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}


//主函数
int main()
{
    int num;
    cout << "Input num: ";
    cin >> num;

    int arr[100];

    cout << "Input data: ";
    for(int i = 0; i < num; ++i){
        cin >> arr[i];
    }

    cout << "After sort: ";
    selectionSort(arr, num);

    print(arr, num);

    return 0;
}
