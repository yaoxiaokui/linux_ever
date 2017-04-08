/*************************************************************************
	> File Name: returnArray.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 14 Jun 2016 12:44:03 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


//错误的版本
void DivArray(int *arr, int size)
{
    for(int i = 0; i < size; ++i){
        arr[i] = arr[i] / arr[0];
    }
}


//正确的版本
void DivArray2(int *arr, int size)
{
    for(int i = size-1; i >= 0; --i){
        //判断除数是否为0
        if(arr[0] == 0){
            cout << "array[0] = 0" << endl;
            return;
        }
        arr[i] = arr[i] / arr[0];
    }
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 7, 8};
    
    cout << "做除法之前: ";
    for(int i = 0; i < sizeof(arr)/sizeof(int); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;

    //DivArray(arr, sizeof(arr)/sizeof(int));
    DivArray2(arr, sizeof(arr)/sizeof(int));

    cout << "做除法之后: ";
    for(int i = 0; i < sizeof(arr)/sizeof(int); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
