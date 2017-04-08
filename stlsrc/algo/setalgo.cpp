/*************************************************************************
	> File Name: setalgo.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Aug 2016 10:53:38 AM CST
 ************************************************************************/

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;


template<typename T>
class display{

public:
    void operator()(const T &x)const{
        cout << x << " ";
    }
};


int main()
{
    int ia1[6] = {1, 3, 5, 7, 9, 11};
    int ia2[7] = {1, 1, 2, 3, 5, 8, 13};

    multiset<int> s1(ia1, ia1+6);
    multiset<int> s2(ia2, ia2+7);

    cout << "s1: ";
    for_each(s1.begin(), s1.end(), display<int>());
    cout << endl;

    cout << "s2: ";
    for_each(s2.begin(), s2.end(), display<int>());
    cout << endl;

    cout << "set_union: ";
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "set_difference: ";
    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

