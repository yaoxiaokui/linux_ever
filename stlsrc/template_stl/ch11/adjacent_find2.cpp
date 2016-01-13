/*************************************************************************
	> File Name: adjacent_find.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月09日 星期六 10时28分30秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <functional>
using namespace std;


int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int N = sizeof(A)/sizeof(int);

    const int * p = adjacent_find(A, A+N, greater<int>());
    if(p != A+N)
        cout << "不是递增的元素是：" << *p << " " << *(p+1) << endl;
    else
        cout << "元素是按递增的顺序排序的." << endl;

    int B[] = {1, 2, 3, 4, 5, 9, 6, 7, 8};
    N = sizeof(B)/sizeof(int);

    p = adjacent_find(B, B+N, greater<int>());
    if(p != B+N)
        cout << "不是递增的元素是：" << *p << " " << *(p+1) << endl;
    else
        cout << "元素是按递增的顺序排序的." << endl;

    return 0;
}
