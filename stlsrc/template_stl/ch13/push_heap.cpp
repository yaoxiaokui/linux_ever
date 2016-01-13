/*************************************************************************
	> File Name: make_heap.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月12日 星期二 10时56分27秒
 ************************************************************************/

#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    const int N = sizeof(A)/sizeof(int);

    cout << "A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;


    make_heap(A, A+N-1);
   
    cout << "make_heaped A(0-----N-1): ";
    copy(A, A+N-1, ostream_iterator<int>(cout, " "));
    cout << endl;

    push_heap(A, A+N);

    cout << "A(0-----N): ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;



    return 0;
}

