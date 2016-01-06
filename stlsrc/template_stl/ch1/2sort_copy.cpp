/*************************************************************************
	> File Name: 1sort_copy.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月29日 星期二 20时12分36秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
using namespace std;


int main()
{
    vector<string> v;
    string temp;

    while(cin >> temp){
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    cout << "This is your sorted string:";
    copy(v.begin(), v.end(), ostream_iterator<string> (cout, "\n"));

    return 0;
}
