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
    int A[] = {1, 2, 3, 4, 5};
    int N = 5;

    cout << "A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "sum of A is " << accumulate(A, A+N, 0) << endl;

    cout << "multiplies of A is " << accumulate(A, A+N, 1, multiplies<int>()) << endl;
    cout << "multiplies of A is " << accumulate(A, A+N, 0, multiplies<int>()) << endl;
    cout << "multiplies of A is " << accumulate(A, A+N, 2, multiplies<int>()) << endl;


    return 0;

}
