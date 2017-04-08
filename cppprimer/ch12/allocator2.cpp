/*************************************************************************
	> File Name: allocator2.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Mar 2017 08:29:13 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <memory>
using namespace std;


int main()
{
    vector<int> v{1, 2, 3, 4};

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;


    allocator<int> alloc;

    auto p = alloc.allocate(v.size() * 2);
    auto q = uninitialized_copy(v.begin(), v.end(), p);
    copy(p, p+v.size(), ostream_iterator<int> (cout, " "));
    cout << endl;

    uninitialized_fill_n(q, v.size(), 42);

    copy(p, p+v.size()*2, ostream_iterator<int> (cout, " "));
    cout << endl;



    return 0;
}
