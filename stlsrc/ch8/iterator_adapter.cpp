/*************************************************************************
	> File Name: iterator_adapter.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Jun 2016 03:08:50 PM CST
 ************************************************************************/

#include <iostream>
#include <iterator>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    ostream_iterator<int> outite(cout, " ");
    int ia[] = {0, 1, 2, 3, 4, 5, 6};
    deque<int> id(ia, ia+7);

    copy(id.begin(), id.end(), outite);
    cout << endl;

    copy(ia+1, ia+2, front_inserter(id));
    copy(id.begin(), id.end(), outite);
    cout << endl;

    copy(ia+1, ia+3, back_inserter(id));
    copy(id.begin(), id.end(), outite);
    cout << endl;


    deque<int>::iterator it = find(id.begin(), id.end(), 5);
    copy(ia+0, ia+3, inserter(id, it));
    copy(id.begin(), id.end(), outite);
    cout << endl;


    copy(id.rbegin(), id.rend(), outite);
    cout << endl;

    istream_iterator<int> inite(cin), eofs;
    copy(inite, eofs, inserter(id, id.begin()));

    copy(id.begin(), id.end(), outite);
    cout << endl;

    return 0;
}

