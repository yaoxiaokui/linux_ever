/*************************************************************************
	> File Name: count.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月09日 星期六 22时49分44秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int A[] = {2, 0, 4, 6, 0, 3, 1, -7};
    const int N = sizeof(A)/sizeof(int);

    cout << "Number of zeros: " << count(A, A+N, 0) << endl;

    return 0;
}

