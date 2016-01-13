/*************************************************************************
	> File Name: fill.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 22时03分19秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v(4);

    fill(v.begin(), v.end(), 10);
    cout << "v: ";
    vector<int>::iterator it;

    for(it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

