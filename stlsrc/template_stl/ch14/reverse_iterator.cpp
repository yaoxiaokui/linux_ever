/*************************************************************************
	> File Name: reverse_iterator.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月12日 星期二 21时31分44秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
    const int N = 10;
    int A[N] = {2, 5, 7, 8, 1, 5, 3, 6, 9, 1};
    list<int> L(A, A+N);

    cout << "L: ";
    copy(L.begin(), L.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "L: ";
    copy(L.rbegin(), L.rend(), ostream_iterator<int>(cout, " "));
    cout << endl;


    cout << "rL: ";
    copy(reverse_iterator<list<int>::iterator>(L.end()), reverse_iterator<list<int>::iterator>(L.begin()), ostream_iterator<int>(cout, " "));
    cout << endl;


    return 0;
}

