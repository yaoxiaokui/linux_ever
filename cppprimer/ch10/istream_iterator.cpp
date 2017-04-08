/*************************************************************************
	> File Name: istream_iterator.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 25 Mar 2017 01:01:13 PM CST
 ************************************************************************/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    # if 0
    istream_iterator<int> in(cin), eof;
    vector<int> v;

    while(in != eof){
        v.push_back(*in++);
    }

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int> (cout, " "));
    cout << endl;
    #endif


    istream_iterator<int> newin(cin), eof2;
    vector<int> v2(newin, eof2);
    cout << "v2: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int> (cout, " "));
    cout << endl;


    return 0;
}
