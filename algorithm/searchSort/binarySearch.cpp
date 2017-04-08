/*************************************************************************
	> File Name: binarySearch.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Jul 2016 02:34:40 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


//使用循环实现二分查找
int binarySearch(int arr[], int value, int left, int right)
{
    int index = 0;

    while(left <= right){
        int mid = (left+right)/2;

        if(value == arr[mid])
            return mid;
        else if(value < arr[mid]){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    return -1;
}

//使用递归实现二分查找
int binarySearch2(int arr[], int value, int left, int right)
{
    if(left <= right){
        int mid = (left+right)/2;
        if(value == arr[mid])
            return mid;
        else if(value < arr[mid]){
            binarySearch2(arr, value, left, mid - 1);
        } 
        else{
            binarySearch2(arr, value, mid + 1, right);
        }
    }

    return -1;
}


//主函数
int main()
{
    int arr[100];

    int num;

    cout << "Input num: ";
    cin >> num;

    cout << "Input data: ";
    for(int i = 0; i < num; ++i){
        cin >> arr[i];
    }

    int value;
    cout << "Input the value to find: ";
    cin >> value;

    int index = binarySearch(arr, value, 0, num-1);
    cout << value << " index in arr is " << index << endl;


    int index2 = binarySearch2(arr, value, 0, num-1);
    cout << value << " index in arr is " << index << endl;


    return 0;
}
