/*************************************************************************
	> File Name: 13reorderArray.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Jun 2016 12:36:20 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


//判断数字n是否是偶数，用于将奇数放在前面，偶数放在后面
bool isEven(int n)
{
    return (n & 1) == 0;
}

//下面是一个模版函数
void Reorder(int * arr, int arrLen, bool (*fun)(int))
{
    if(arr == NULL || arrLen == 0)
        return;

    int firstIndex = 0;
    int lastIndex = arrLen-1;

    while(firstIndex < lastIndex){

        //如果函数fun返回false，则向后移动
        while(firstIndex<lastIndex && !fun(arr[firstIndex]))
            ++firstIndex;

        //如果函数fun返回true，则向前移动
        while(firstIndex<lastIndex && fun(arr[lastIndex]))
            --lastIndex;


        //交换这两个值
        if(firstIndex < lastIndex){
            //交换
            int temp = arr[lastIndex];
            arr[lastIndex] = arr[firstIndex];
            arr[firstIndex] = temp;
            
            ++firstIndex;
            --lastIndex;
        }
    }
}


//让奇数在前面，偶数在后面
void ReorderArray(int * arr, int arrLen)
{
    Reorder(arr, arrLen, isEven);
}


//主测试函数
int main()
{
    int arr[] = {2, 3, 5, 6, 7, 8, 9, 0, 11};
    int arrLen = sizeof(arr)/sizeof(int);


    for(int i = 0; i < arrLen; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;

    ReorderArray(arr, arrLen);

    for(int i = 0; i < arrLen; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
