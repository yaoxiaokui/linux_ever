/*************************************************************************
	> File Name: heapSort.cpp 
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Jul 2016 03:15:10 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;


//调整二叉堆中结点i
void heapify(int arr[], int num, int i)
{
    int largest = i;
    int leftIndex = 2*i + 1;
    int rightIndex = 2*i + 2;

    if(leftIndex < num && arr[leftIndex] > arr[largest]){
        largest = leftIndex;
    }

    if(rightIndex < num && arr[rightIndex] > arr[largest])
        largest = rightIndex;

    //让largest指向最大的值
    if(largest != i){
        swap(arr[largest], arr[i]);

        //递归调用
        heapify(arr, num, largest);
    }

}

//堆排序,从小到大排序
void heapSort(int arr[], int num)
{
    //建立二叉堆,最大堆
    for(int i = num/2; i >= 0; --i){
        heapify(arr, num, i);
    }

    //依次删除最大堆的根结点
    for(int i = num-1; i >= 0; --i){
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
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
    heapSort(arr, num);

    print(arr, num);

    return 0;
}
