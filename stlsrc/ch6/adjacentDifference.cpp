/*************************************************************************
	> File Name: accumulate.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 02 Sep 2016 08:45:15 AM CST
 ************************************************************************/

#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


int main()
{
    int ia[5] = {1, 2, 3, 4, 5};
    vector<int> v(ia, ia+5);

    //cout << accumulate(ia, ia+5, 0) << endl;
    //cout << accumulate(v.begin(), v.end(), 0) << endl;
    vector<int> diff(4);
    adjacent_difference(v.begin(), v.end(), diff.begin());
    copy(diff.begin(), diff.end(), ostream_iterator<int>(cout, " "));
    cout << endl;



    return 0;
}
