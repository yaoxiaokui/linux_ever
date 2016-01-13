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
    int A[] = {1, 2, 3, 4, 5, 6};
    const int N = sizeof(A)/sizeof(int);

    cout << "A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;


    make_heap(A, A+N);
   
    cout << "make_heaped A): ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    int n = N;

    while(n>1){
        copy(A, A+N, ostream_iterator<int>(cout, " "));
        cout << endl;
        pop_heap(A, A+n);
        --n;
    }

    cout << endl;
    cout << "A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;



    return 0;
}

