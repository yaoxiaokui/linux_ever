/*************************************************************************
	> File Name: swap.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 14时52分04秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    int a = 100;
    int b = 200;
    cout << "a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "a = " << a << ", b = " << b << endl;
    
    vector<int> v1;
    vector<int> v2;

    for (int i = 1; i < 6; ++i){
        v1.push_back(i+1);
        v2.push_back(i+2);
    }

    cout << "v1: ";
    copy(v1.begin(), v1.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    cout << "v2: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    swap(v1, v2);
    cout << "v1: ";
    copy(v1.begin(), v1.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    cout << "v2: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    return 0;
}

