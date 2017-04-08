/*************************************************************************
	> File Name: mergeSort.cpp 
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Jul 2016 03:15:10 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;


void mergeSort(int arr[], int left, int mid, int right)
{
    int leftArrLen = mid-left+1;
    int rightArrLen = right - mid;

    //用来保存arr[left]到arr[mid]的值
    int leftArr[leftArrLen];

    //用来保存arr[mid+1]到arr[right]的值
    int rightArr[rightArrLen];

    //拷贝左边的数组
    for(int i = 0; i < leftArrLen; ++i){
        leftArr[i] = arr[left+i];
    }

    //拷贝右边的数组
    for(int i = 0; i < rightArrLen; ++i){
        rightArr[i] = arr[mid+1+i];
    }

    int leftArrIndex = 0;
    int rightArrIndex = 0;
    int arrIndex = 0;

    //比较左数组和右数组的大小，将比较小的值赋给原来的数组
    while(leftArrIndex < leftArrLen && rightArrIndex < rightArrLen){
        if(leftArr[leftArrIndex] < rightArr[rightArrIndex]){
            arr[left + arrIndex] = leftArr[leftArrIndex];
            leftArrIndex++;
        }
        else{
            arr[left+arrIndex] = rightArr[rightArrIndex];
            rightArrIndex++;
        }

        arrIndex++;
    }

    //如果剩下的是左数组的元素，则将左数组的元素拷贝到原来的数组
    while(leftArrIndex < leftArrLen){
        arr[left + arrIndex] = leftArr[leftArrIndex];
        arrIndex++;
        leftArrIndex++;
    }

    //如果剩下的是右数组的元素，则将右数组的元素拷贝到原来的数组
    while(rightArrIndex < rightArrLen){
        arr[left + arrIndex] = rightArr[rightArrIndex];
        arrIndex++;
        rightArrIndex++;
    }

}

//归并排序
void mergeSort(int arr[], int left, int right)
{
    if(left < right){
        int mid = (left + right)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        //合并上面分治之后的数组
        mergeSort(arr, left, mid, right);
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
    mergeSort(arr, 0, num-1);

    print(arr, num);

    return 0;
}
