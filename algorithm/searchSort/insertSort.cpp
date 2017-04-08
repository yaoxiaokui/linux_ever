/*************************************************************************
	> File Name: insertSort.cpp 
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Jul 2016 03:15:10 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

//插入排序
void insertSort(int arr[], int num)
{
    int key, j;

    //loop i = 1....num-1;
    for(int i = 1; i < num; ++i){
        key = arr[i];//保存arr[i]


        //将0到i-1的元素向后移动
        //直到arr[j]元素小于等于key，或移动到第一个元素位置
        for(j = i-1; j >= 0 && arr[j] > key; --j){
            arr[j+1] = arr[j];
        }

        arr[j+1] = key;
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
    insertSort(arr, num);

    print(arr, num);

    return 0;
}
