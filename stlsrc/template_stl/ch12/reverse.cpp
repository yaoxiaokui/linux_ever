/*************************************************************************
	> File Name: reverse.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 10时33分22秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    reverse(v.begin(), v.end());
    cout << "reversed v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;


    return 0;
}

