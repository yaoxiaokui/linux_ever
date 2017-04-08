/*************************************************************************
	> File Name: rbeginend.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 25 Mar 2017 01:43:26 PM CST
 ************************************************************************/

#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int val;

    while(cin >> val){
        v.push_back(val);
    }

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    cout << "rv: ";
    for(auto r_iter = v.rbegin(); r_iter != v.rend(); ++r_iter)
        cout << *r_iter << " ";
    cout << endl;


    return 0;
}
