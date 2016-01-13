/*************************************************************************
	> File Name: lower_bound.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 21时54分45秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;


int main()
{
    int A[] = {1, 2, 3, 3, 3, 5, 8};
    const int N = sizeof(A)/sizeof(int);

    cout << "A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    for(int i = 1; i <= 5; ++i){
        pair<int *, int *> result = equal_range(A, A+N, i);
        cout << "Searching for " << i << ", lower index = " << result.first-A << ", upper index = " << result.second - A << ", ";
        if(result.first < A+N)
            cout << "A[" << result.first - A << "] = " << *(result.first) << ", ";
        else
            cout << "which is off the end" << endl;
        if(result.second < A+N)
            cout << "A[" << result.second - A << "] = " << *(result.second) << endl;
        else
            cout << "which is off the end" << endl;
    }

    return 0;
}
