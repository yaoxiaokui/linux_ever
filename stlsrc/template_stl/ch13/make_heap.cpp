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
    int A[] = {1, 4, 2, 8, 5, 7};
    const int N = sizeof(A)/sizeof(int);

    cout << "A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;


    make_heap(A, A+N);
   
    cout << "make_heaped A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    sort_heap(A, A+N);

    cout << "sort_heaped A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;



    return 0;
}

