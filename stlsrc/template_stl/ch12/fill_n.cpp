/*************************************************************************
	> File Name: fill_n.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 22时05分37秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    vector<int> v(10, 3);
    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    fill_n(v.begin(), 4, 100);

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    return 0;
}

