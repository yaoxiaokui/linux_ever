/*************************************************************************
	> File Name: quicksort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016???1???2???星期???16???3???1???
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

//这是插入排序的算法，用于排序数量小于10的序列
void insert_sort(vector<int> & data, int left, int right)
{
    int j;
    for (int i = left + 1; i <= right; ++i){
        int tmp = data[i];
        for (j = i; j > 0 && tmp < data[j-1]; j--){
            data[j] = data[j-1];
        }
        data[j] = tmp;
    }
}

//获得枢纽元
template<class T>
const T & median3(vector<T> & a, int left, int right)
{
    int center = (left+right)/2;
    
    if(a[center] < a[left])
        swap(a[center], a[left]);
    if(a[right] < a[left])
        swap(a[right], a[left]);
    if(a[right] < a[center])
        swap(a[center], a[right]);

    //将枢纽元和最后一个元素互换位置
    swap(a[center], a[right-1]);
    return a[right-1];
}

//快速排序算法
template<class T>
void quicksort(vector<T> & a, int left, int right)
{
    //排序的元素的个数大于10,选择快速排序，
    if (left + 10 <= right){
        T pivot = median3(a, left, right);//获得枢纽元

        //开始排序
        int i = left, j = right - 1;
        for ( ; ; ){
            while(a[++i] < pivot){}
            while(a[--j] > pivot){}

            if(i < j)
                swap(a[i], a[j]);
            else
                break;
        }

        swap(a[i], a[right-1]);//恢复枢纽元的位置

        quicksort(a, left, i-1);
        quicksort(a, i + 1, right);
    }
    else{
        //排序的元素的个数小于10，用插入排序算法来排序
        insert_sort(a, left, right);
    }
}

int main()
{
    vector<int> v;
    v.push_back(23);
    v.push_back(12);
    v.push_back(9);
    v.push_back(34);
    v.push_back(11);
    v.push_back(7);
    v.push_back(3);
    v.push_back(10);
    v.push_back(8);
    v.push_back(25);
    v.push_back(89);
    v.push_back(11);
    v.push_back(90);
    v.push_back(100);
    v.push_back(45);
    v.push_back(28);
    v.push_back(26);

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    quicksort(v, 0, v.size() -1); 

    cout << "quicksorted v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
