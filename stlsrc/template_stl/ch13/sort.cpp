/*************************************************************************
	> File Name: sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 16时55分52秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

int main()
{
    int a[] = {1, 4, 2, 8, 5, 7};
    const int N = sizeof(a)/sizeof(int);

    cout << "a: ";
    copy(a, a+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    sort(a, a+N);

    cout << "sorted a: ";
    copy(a, a+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    sort(a, a+N, greater<int>());

    cout << "sorted a: ";
    copy(a, a+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

