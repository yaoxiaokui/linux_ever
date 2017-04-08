/*************************************************************************
	> File Name: greater.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Apr 2017 02:02:38 PM CST
 ************************************************************************/

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int main()
{
    vector<string> v;
    string word;

    while(cin >> word){
        v.push_back(word);
    }

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<string> (cout, " "));
    cout << endl;

    sort(v.begin(), v.end(), greater<string>());

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<string> (cout, " "));
    cout << endl;

    sort(v.begin(), v.end(), less<string>()); 

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<string> (cout, " "));
    cout << endl;

    return 0;
}
