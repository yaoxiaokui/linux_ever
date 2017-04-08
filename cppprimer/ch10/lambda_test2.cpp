/*************************************************************************
	> File Name: lambda_test2.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Mar 2017 02:15:05 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main()
{
    vector<int> v;
    int val;

    while(cin >> val){
        v.push_back(val);
    }

    for_each(begin(v), end(v), [](const int val){cout << val << " "; });
    cout << endl;

   #if 0 
    for_each(begin(v), end(v), [](int & val){
        if(val < 0)
            val = -1 * val;
    });
    #endif

    transform(v.begin(), v.end(), v.begin(), [](int val) ->int {
        if(val < 0)
            return -val;
        else
            return val;
    });

    for_each(begin(v), end(v), [](const int val){cout << val << " "; });
    cout << endl;


    return 0;
}
