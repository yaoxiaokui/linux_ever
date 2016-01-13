/*************************************************************************
	> File Name: partition.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 11时09分06秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

bool is_even(int x)
{
    return x % 2 == 0;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int N = sizeof(A)/sizeof(int);

    cout << "A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    partition(A, A + N, is_even);

    cout << "partitioned A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

