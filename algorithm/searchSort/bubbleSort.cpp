/*************************************************************************
	> File Name: bubbleSort.cpp 
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Jul 2016 03:15:10 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

//冒泡排序
void bubbleSort(int arr[], int num)
{
    //一共进行num-1次遍历
    for(int i = 0; i < num-1; ++i){

        //将最大的元素放在数组的最后一个位置
        for(int j = 0; j < num-1-i; ++j){
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
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
    bubbleSort(arr, num);

    print(arr, num);

    return 0;
}
