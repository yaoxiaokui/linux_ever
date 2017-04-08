/*************************************************************************
	> File Name: copy.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 27 Jul 2016 12:56:07 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdlib.h>
using namespace std;

void print(vector<int> & v)
{
    copy(v.begin(), v.end(), ostream_iterator<int> (cout, " "));
    cout << endl;
}


bool absEqual(int x1, int x2)
{
    return abs(x1) == abs(x2);
}


int main()
{
    vector<int> v{1, 2, -3, 2, 4, 5, -6, 2, -6};
    vector<int> v2(v);

    cout << "v: ";
    print(v);

    if(equal(v.begin(), v.end(), v2.begin()))
        cout << "v1 == v2" << endl;
    else
        cout << "v1 != v2" << endl;
        

    v[0] = -1;

    if(equal(v.begin(), v.end(), v2.begin()))
        cout << "v1 == v2" << endl;
    else
        cout << "v1 != v2" << endl;

    if(equal(v.begin(), v.end(), v2.begin(), absEqual))
        cout << "v1 == v2" << endl;
    else
        cout << "v1 != v2" << endl;

    return 0;
}

