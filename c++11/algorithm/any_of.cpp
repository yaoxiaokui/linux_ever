/*************************************************************************
	> File Name: any_of.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 27 Jul 2016 12:50:39 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 4, 3, 2, 1};

    sort(v.begin(), v.end());

    if(binary_search(v.begin(), v.end(), 5))
        cout << "5 is found" << endl;
    else
        cout << "5 is not found" << endl;

    if(binary_search(v.begin(), v.end(), 6))
        cout << "6 is found" << endl;
    else
        cout << "6 is not found" << endl;
        


    return 0;
}

