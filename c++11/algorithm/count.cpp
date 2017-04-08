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
using namespace std;

void print(vector<int> & v)
{
    copy(v.begin(), v.end(), ostream_iterator<int> (cout, " "));
    cout << endl;
}



int main()
{
    vector<int> v{1, 2, -3, 2, 4, 5, -6, 2, -6};

    cout << "v: ";
    print(v);

    cout << "count of 2 = " << count(v.begin(), v.end(), 2) << endl;
    cout << "count of -6 = " << count(v.begin(), v.end(), -6) << endl;
    cout << "count of 4 = " << count(v.begin(), v.end(), 4) << endl;


    return 0;
}

