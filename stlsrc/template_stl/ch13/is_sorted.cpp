/*************************************************************************
	> File Name: is_sorted.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 21时33分15秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;

int main()
{
    int A[] = {1, 4, 2, 8, 5, 7};
    const int N = sizeof(A)/sizeof(int);

    cout << "is_sorted(A, A) = " << is_sorted(A, A) << endl;
    cout << "is_sorted(A, A, greater<int>()) = " << is_sorted(A, A, greater<int>()) << endl;

    cout << "is_sorted(A, A+N) = " << is_sorted(A, A+N) << endl;
    cout << "is_sorted(A, A+N, greater<int>()) = " << is_sorted(A, A+N, greater<int>()) << endl;

    sort(A, A+N);

    cout << "After sort of A: " << endl;
    cout << "is_sorted(A, A+N) = " << is_sorted(A, A+N) << endl;
    cout << "is_sorted(A, A+N, greater<int>()) = " << is_sorted(A, A+N, greater<int>()) << endl;

    sort(A, A+N, greater<int>());

    cout << "After greater sort of A: " << endl;
    cout << "is_sorted(A, A+N) = " << is_sorted(A, A+N) << endl;
    cout << "is_sorted(A, A+N, greater<int>()) = " << is_sorted(A, A+N, greater<int>()) << endl;

    return 0;
}

