/*************************************************************************
	> File Name: findKelements.cpp 
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Jul 2016 03:15:10 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

//使用冒泡排序获得最大的k的值
//进行k次冒泡操作之后，最大的k个值会存放在数组的末尾
void bubbleSort(int arr[], int num, int k)
{
    //一共进行k次遍历
    //时间复杂度为O(N*k)
    for(int i = 0; i < k; ++i){

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

    int k;

    cout << "Input data: ";
    for(int i = 0; i < num; ++i){
        cin >> arr[i];
    }

    cout << "Input K: ";
    cin >> k;

    bubbleSort(arr, num, k);
    cout << k << "个最大值为: ";
    print(arr+num-k, k);

    return 0;
}
