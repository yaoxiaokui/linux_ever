/*************************************************************************
	> File Name: remove.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 09时22分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <functional>
using namespace std;

int main()
{

    vector<int> v;
    v.push_back(-2);
    v.push_back(0);
    v.push_back(-1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    vector<int> v2;

    remove_copy_if(v.begin(), v.end(), back_inserter(v2), bind2nd(less<int>(), 1));

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "v2: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
