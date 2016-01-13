/*************************************************************************
	> File Name: negate.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月13日 星期三 09时17分12秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector> 
#include <cstdlib>
using namespace std; 

int main()
{
    int v1[] = {-1, 2, 0, -4, -5, 0, 45, 0, 3};
    const int N = sizeof(v1)/sizeof(int);

    cout << "v1: ";
    copy(v1, v1+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    stable_partition(v1, v1+N, bind2nd(greater<int>(), 0));
    //partition(v1, v1+N, bind2nd(equal_to<int>(), 0));

    cout << "v1: ";
    copy(v1, v1+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    sort(v1, v1+N, greater<int>());
    cout << "sorted v1: ";
    copy(v1, v1+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

