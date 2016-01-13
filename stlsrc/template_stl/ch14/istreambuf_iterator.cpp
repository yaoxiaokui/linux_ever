/*************************************************************************
	> File Name: istream_iterator.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月12日 星期二 19时30分38秒
 ************************************************************************/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    istreambuf_iterator<char> first(cin);
    istreambuf_iterator<char> last;

    vector<char> v(first, last);
    //vector<char> v;

    //copy(istreambuf_iterator<char>(cin), istreambuf_iterator<char>(), back_inserter(v));

    cout << endl;
    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<char>(cout, ","));
    cout << endl;

    return 0;
}

