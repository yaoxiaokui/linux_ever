/*************************************************************************
	> File Name: 13reorderArray.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Jun 2016 12:36:20 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//让奇数在前面，偶数在后面
void ReorderArray(int * arr, int arrLen)
{
    int firstIndex = 0;
    int lastIndex = arrLen-1;

    while(firstIndex < lastIndex){
        if(arr[firstIndex] % 2 == 1)
            ++firstIndex;

        if(arr[lastIndex] % 2 == 0)
            --lastIndex;
        else if(arr[firstIndex]%2 == 0){
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
void ReorderArray2(int * arr, int arrLen)
{
    int firstIndex = 0;
    int lastIndex = arrLen-1;

    while(firstIndex < lastIndex){

        //前面的数如果是奇数，则向后移动
        while(firstIndex<lastIndex && (arr[firstIndex] & 0x1)!=0)
            ++firstIndex;

        //后面的数如果是偶数，则向前移动
        while(firstIndex<lastIndex && (arr[lastIndex] & 0x1)==0)
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


int main()
{
    int arr[] = {2, 3, 5, 6, 7, 8, 9, 0, 11};
    int arrLen = sizeof(arr)/sizeof(int);


    for(int i = 0; i < arrLen; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;

    //ReorderArray(arr, arrLen);
    ReorderArray2(arr, arrLen);


    for(int i = 0; i < arrLen; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
