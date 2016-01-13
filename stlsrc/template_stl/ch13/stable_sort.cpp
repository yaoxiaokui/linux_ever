/*************************************************************************
	> File Name: stable_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 17时09分02秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
using namespace std;

bool less_nocase(char x, char y)
{
    return tolower(x) < tolower(y);
}

int main()
{
    char A[] = "fdBeACFDbEac";
    const int N = sizeof(A)-1;

    cout << "A: ";
    cout << A << endl;

    stable_sort(A, A+N, less_nocase);
    cout << "A: " << A << endl;

    return 0;
}

