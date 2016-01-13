/*************************************************************************
	> File Name: generate.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 22时08分53秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iterator>
using namespace std;

int main()
{
    vector<int> v(10);
    
    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    generate(v.begin(), v.end(), rand);

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

