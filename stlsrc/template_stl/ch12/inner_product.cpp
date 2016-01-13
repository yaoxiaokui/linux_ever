/*************************************************************************
	> File Name: accumulate.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 11时41分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
using namespace std;


int main()
{
    int A1[] = {1, 2, 3};
    int A2[] = {4, 1, -1};
    int N = 3;

    cout << "A1: ";
    copy(A1, A1+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "A2: ";
    copy(A2, A2+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "inner_product of A1 and A2 is " << inner_product(A1, A1+N, A2, 0) << endl;

    return 0;
}
