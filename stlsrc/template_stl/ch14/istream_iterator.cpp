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
    vector<int> v;

    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    cout << endl;
    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

