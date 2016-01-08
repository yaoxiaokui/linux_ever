/*************************************************************************
	> File Name: find_if.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月08日 星期五 21时02分36秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int A[] = {4, 1, 0, 3, 2, 0, 6};
    const int N = sizeof(A)/sizeof(int);
    int *p = find_if(A, A+N, bind2nd(equal_to<int>(), 0));
    cout << "*(A+N-1) = " << *(A+N-1) << endl;
    if(p == A+N)
        cout << "not find 0" << endl;
    else 
        cout << "find 0, *p = " << *p << endl;

    p = find_if(A, A+N, bind2nd(equal_to<int>(), 8));

    if(p == A+N)
        cout << "not find 8" << endl;
    else 
        cout << "find 8, *p = " << *p << endl;
    
    return 0;
}

