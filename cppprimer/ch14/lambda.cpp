/*************************************************************************
	> File Name: lambda.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Apr 2017 10:57:30 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

class ShorterString{
public:
    bool operator()(const string & s1, const string & s2){
        return s1.size() < s2.size();
    }

};


int main()
{
    string word;
    vector<string> v;

    while(cin >> word){
        v.push_back(word);
    }

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    cout << "v: ";
    for_each(v.begin(), v.end(), [](const string & str){cout << str << " ";});
    cout << endl;

    //stable_sort(v.begin(), v.end(), [](const string & s1, const string & s2){ return s1.size() < s2.size(); });
    stable_sort(v.begin(), v.end(), ShorterString());

    cout << "alfter sort v: ";
    for_each(v.begin(), v.end(), [](const string & str){cout << str << " ";});
    cout << endl;

    return 0;
}
