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
using namespace std;

int main()
{
    list<int> L;
    L.push_front(3);
    front_insert_iterator<list<int> > ii(L);
/*
    *ii++ = 0;
    *ii++ = 1;
    *ii++ = 2;
*/
    *ii = 0;
    *ii = 1;
    *ii = 2;

    cout << "L: ";
    copy(L.begin(), L.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

