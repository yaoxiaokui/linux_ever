/*************************************************************************
	> File Name: copy.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 27 Jul 2016 12:56:07 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

void print(vector<int> & v)
{
    copy(v.begin(), v.end(), ostream_iterator<int> (cout, " "));
    cout << endl;
}


bool isOdd(int x)
{
    return x & 1;
}

bool isEven(int x)
{
    return !(x&1);
}

int main()
{
    vector<int> v{1, 2, -3, 2, 4, 5, -6, 2, -6};

    cout << "v: ";
    print(v);

    cout << "count of odd number = " << count_if(v.begin(), v.end(), isOdd) << endl;
    cout << "count of even number = " << count_if(v.begin(), v.end(), isEven) << endl;


    return 0;
}

