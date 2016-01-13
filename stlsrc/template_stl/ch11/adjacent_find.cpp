/*************************************************************************
	> File Name: adjacent_find.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月09日 星期六 10时28分30秒
 ************************************************************************/

#include<iostream>
#include <algorithm>

using namespace std;


int main()
{
    int A[] = {1, 2, 3, 3, 4, 5};
    const int N = sizeof(A)/sizeof(int);

    const int * p = adjacent_find(A, A+N);
    if(p != A+N)
        cout << "重复的元素是：" << *p << endl;
    else
        cout << "不存在重复的元素" << endl;

    return 0;
}
