/*************************************************************************
	> File Name: negate.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月13日 星期三 09时17分12秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector> 
#include <cstdlib>
using namespace std; 

int main()
{
    const int N = 10;
    vector<int> v1(N);
    vector<int> v2(N);

    generate(v1.begin(), v1.end(), rand);

    cout << "v1: ";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    transform(v1.begin(), v1.end(), v2.begin(), negate<int>());

    cout << "v2: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;


    


    return 0;
}

