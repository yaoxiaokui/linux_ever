/*************************************************************************
	> File Name: lower_bound.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 21时54分45秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;


int main()
{
    int A[] = {1, 2, 3, 3, 3, 5, 8};
    const int N = sizeof(A)/sizeof(int);

    cout << "A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    for(int i = 1; i <= 10; ++i){
        int * p = upper_bound(A, A+N, i);
        cout << "Searching for " << i << ", index = " << p-A << ", ";
        if(p != A+N)
            cout << "A[" << p-A << "] = " << *p << endl;
        else
            cout << "which is off the end" << endl;
    }

    return 0;
}
