/*************************************************************************
	> File Name: partial_sum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 12时01分37秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main()
{
    const int N = 5;
    int A[5];
    fill(A, A + N, 1);
    cout << "A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "partial_sum(0, 4): ";
    partial_sum(A, A+4, ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

