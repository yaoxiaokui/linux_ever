/*************************************************************************
	> File Name: merge_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016???1???1???星期一 15???6???6???
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


template<class T>
void merge(vector<T> & a, vector<T> & tmpArray, int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while(leftPos <= leftEnd && rightPos <= rightEnd){
        if(a[leftPos] <= a[rightPos])
            tmpArray[tmpPos++] = a[leftPos++];
        else
            tmpArray[tmpPos++] = a[rightPos++];
    }

    while(leftPos <= leftEnd)
        tmpArray[tmpPos++] = a[leftPos++];

    while(rightPos <= rightEnd)
        tmpArray[tmpPos++] = a[rightPos++];

    for (int i = 0; i < numElements; i++, rightEnd--)
        a[rightEnd] = tmpArray[rightEnd];
}

template<class T>
void mergeSort(vector<T> &a, vector<T> & tmpArray, int left, int right)
{
    if (left < right){
        int center = (left+right)/2;
        mergeSort(a, tmpArray, left, center);
        mergeSort(a, tmpArray, center+1, right);
        merge(a, tmpArray, left, center+1, right);
    }
}

template<class T>
void mergeSort(vector<T> & a)
{
    vector<T> tmpArray(a.size());

    mergeSort(a, tmpArray, 0, a.size()-1);
}

int main()
{
    vector<int> v;
    v.push_back(12);
    v.push_back(8);
    v.push_back(3);
    v.push_back(8);
    v.push_back(10);
    v.push_back(1);
    v.push_back(2);
    v.push_back(14);
    v.push_back(15);
    v.push_back(9);
    v.push_back(7);
    v.push_back(4);

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    mergeSort(v);

    cout << "mergeSorted v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
