/*************************************************************************
	> File Name: adjacent_find.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 27 Jul 2016 11:57:16 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    vector<int> v{1, 2, 3, 4, 4, 5, 6, 6, 7, 8};

    auto it = adjacent_find(v.begin(), v.end());
    if(it != v.end())
        cout << *it << endl;

    it = adjacent_find(++it, v.end());
    if(it != v.end())
        cout << *it << endl;



    return 0;
}
