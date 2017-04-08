/*************************************************************************
	> File Name: backInserter.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Mar 2017 12:18:12 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    vector<int> v;

    fill_n(back_inserter(v), 10, 1);

    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;


    return 0;
}
