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
    vector<int> v{1, 2, 3, 4, 5, 6};
    vector<int> v2(6);

    cout << "v: ";
    print(v);

    cout << "v2: ";
    print(v2);

    copy_backward(v.begin(), v.end(), v2.end());
    cout << "v2: ";
    print(v2);




    return 0;
}

