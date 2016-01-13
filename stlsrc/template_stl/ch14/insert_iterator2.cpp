/*************************************************************************
	> File Name: front_insert_iterator.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月12日 星期二 11时34分42秒
 ************************************************************************/

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <set>
using namespace std;

int main()
{
    const int N = 6;
    int A1[N] = {1, 3, 5, 7, 9, 11};
    int A2[N] = {1, 2, 3, 4, 5, 6};

    set<int> result;
    merge(A1, A1+N, A2, A2+N, inserter(result, result.begin()));


/*
    *ii++ = 0;
    *ii++ = 1;
    *ii++ = 2;
*/

    cout << "result: ";
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

