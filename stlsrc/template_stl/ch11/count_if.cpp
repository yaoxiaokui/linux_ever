/*************************************************************************
	> File Name: count_if.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 11时30分14秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int A[] = {2, 0, 4, 6, 0, 3, 1, -7};
    const int N = sizeof(A)/sizeof(int);

    cout << "the number of 0 is " << count_if(A, A+N, bind2nd(equal_to<int>(), 0)) << endl;

    return 0;
}
