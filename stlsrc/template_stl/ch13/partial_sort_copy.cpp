/*************************************************************************
	> File Name: partial_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 21时15分18秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    int A[] = {7, 2, 6, 11, 9, 3, 12, 10, 8, 4, 1, 5};
    const int N = sizeof(A)/sizeof(int);
    cout << "A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> v(4);

    partial_sort_copy(A, A+N, v.begin(), v.end());
    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

