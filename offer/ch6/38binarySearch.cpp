/*************************************************************************
	> File Name: binerySearch.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Jul 2016 09:25:18 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;


const int MAXLEN = 100;

//找到k在数组中第一个出现的下标
int findFirstIndex(int *array, int length, int k)
{
    if(array == NULL || length == 0){
        return -1;
    }

    int first = 0;
    int last = length - 1;

    while(first <= last){
        int mid = (first+last)/2;

        //找到了该元素
        if(array[mid] == k){
            if(array[mid-1] == k)//如果中间元素的前一个元素也是k，则在前部分查找
                last = mid - 1;
            else
                return mid;
        }
        else if(array[mid] < k){
            first = mid + 1;
        }
        else
            last = mid - 1;
    }

    return -1;
}
//找到k在数组中最后出现的下标
int findLastIndex(int *array, int length, int k)
{
    if(array == NULL || length == 0){
        return -1;
    }

    int first = 0;
    int last = length - 1;

    while(first <= last){
        int mid = (first+last)/2;

        //找到了该元素
        if(array[mid] == k){
            if(array[mid+1] == k)//如果中间元素的后一个元素也是k，则在后部分查找
                first = mid + 1;
            else
                return mid;
        }
        else if(array[mid] < k){
            first = mid + 1;
        }
        else
            last = mid - 1;
    }

    return -1;
}


//二分查找
int binarySearch(int *array, int length, int k)
{
    if(array == NULL || length == 0){
        return -1;
    }

    int first = 0;
    int last = length-1;

    while(first <= last){
        int mid = (first+last)/2;

        //找到了该元素
        if(array[mid] == k){
            return mid;
        }
        else if(array[mid] < k){
            first = mid + 1;
        }
        else{
            last = mid - 1;
        }
    }

    return -1;
}

//求数组中k出现的次数
int getNumberOfK(int * array, int length, int k)
{
    if(array == NULL || length == 0)
        return 0;

    int num = 0;

    int firstIndexOfK = findFirstIndex(array, length, k);
    int lastIndexOfK = findLastIndex(array, length, k);

    if(firstIndexOfK > -1 && lastIndexOfK > -1){
        num = lastIndexOfK - firstIndexOfK + 1;
    }

    return num;

}

int main()
{

    int length = 0;
    int array[MAXLEN];
    
    cout << "数组数组的长度: ";
    cin >> length;
    cout << "输入数组的元素: ";
    for(int i = 0; i < length; ++i){
        cin >> array[i];
    }

    int k = 0;
    cout << "输入要查找的元素: ";
    cin >> k;

    int index = binarySearch(array, length, k);
    if(index == -1){
        cout << "not find the " << k << endl;
    }
    else
        cout << k << " in the array " << index << ", array[index] = " << array[index] << endl;


    int num = getNumberOfK(array, length, k);
    cout << k << "出现的次数是: " << num << endl;


    return 0;
}
