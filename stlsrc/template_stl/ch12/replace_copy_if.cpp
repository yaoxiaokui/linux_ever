/*************************************************************************
	> File Name: replace_copy.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 16时57分20秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(-2);
    v1.push_back(3);
    v1.push_back(-1);

    vector<int> v2(v1.size());

    cout << "v1: ";
    copy(v1.begin(), v1.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    replace_copy_if(v1.begin(), v1.end(), v2.begin(), bind2nd(less<int>(), 0), 0);

    cout << "v2: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    return 0;
}
