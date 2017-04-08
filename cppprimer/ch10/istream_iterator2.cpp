/*************************************************************************
	> File Name: istream_iterator.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 25 Mar 2017 01:01:13 PM CST
 ************************************************************************/

#include <iostream>
#include <iterator>
#include <functional>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    istream_iterator<int> in(cin), eof;
    vector<int> v;

    while(in != eof){
        v.push_back(*in++);
    }

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int> (cout, " "));
    cout << endl;


    ostream_iterator<int> os(cout, ", ");
    for(int val : v)
        os = val;
    cout << endl;

    # if 0
    istream_iterator<int> in(cin), eof2;
    cout << accumulate(in, eof2, 0) << endl;
    #endif


    return 0;
}
