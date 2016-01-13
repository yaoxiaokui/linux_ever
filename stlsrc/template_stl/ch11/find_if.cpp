/*************************************************************************
	> File Name: find_if.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月08日 星期五 21时02分36秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <list>
#include <functional>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(-3);
    l.push_back(0);
    l.push_back(3);
    l.push_back(-2);
    l.push_back(7);

    list<int>::iterator result = find_if(l.begin(), l.end(), bind2nd(greater<int>(), 0));
    if(result == l.end())
        cout << "no element's value is greater than 0" << endl;
    else
        cout << "*result = " << *result << endl;


    return 0;
}


int main0()
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

