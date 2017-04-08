/*************************************************************************
	> File Name: hash_set.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 11 Jun 2016 03:59:19 PM CST
 ************************************************************************/

#include <iostream>
#include <hash_set>
#include <iterator>
#include <algorithm>
using namespace std;
using namespace __gnu_cxx;


int main()
{
    hash_set<int> iSet;

    iSet.insert(3);
    iSet.insert(196);
    iSet.insert(1);
    iSet.insert(389);
    iSet.insert(194);
    iSet.insert(387);

    ostream_iterator<int> output(cout, " ");

    cout << "iSet: ";
    copy(iSet.begin(), iSet.end(), output);
    cout << endl;


    return 0;
}

