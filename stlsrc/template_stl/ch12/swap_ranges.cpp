/*************************************************************************
	> File Name: swap_ranges.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 15时08分31秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);

    vector<int> v2;
    v2.push_back(21);
    v2.push_back(23);

    cout << "v1: ";
    copy(v1.begin(), v1.end(), ostream_iterator<int> (cout, " "));
    cout << endl;
    cout << "v2: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int> (cout, " "));
    cout << endl;


    swap_ranges(v1.begin(), v1.end(), v2.begin());

    cout << "v1: ";
    copy(v1.begin(), v1.end(), ostream_iterator<int> (cout, " "));
    cout << endl;
    cout << "v2: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int> (cout, " "));
    cout << endl;


    return 0;
}

