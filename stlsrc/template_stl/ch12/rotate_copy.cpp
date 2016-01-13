/*************************************************************************
	> File Name: rotate.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 10时42分18秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    const int N = sizeof(A)/sizeof(int);

    cout << "old A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "rotate(1) A: ";
    rotate_copy(A, A+1, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;


    cout << "rotate(N-1) A: ";
    rotate_copy(A, A+N-1, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

