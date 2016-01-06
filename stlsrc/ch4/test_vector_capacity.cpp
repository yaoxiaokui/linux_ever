/*************************************************************************
	> File Name: test_vector_capacity.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月20日 星期日 10时54分17秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int> v;

    cout << "v.size() " << v.size() << ", v.capacity() " << v.capacity() << endl;
    v.push_back(1);
    v.push_back(2);
    cout << "v.size() " << v.size() << ", v.capacity() " << v.capacity() << endl;

    return 0;
}
