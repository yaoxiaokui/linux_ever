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
    //hash_set<const char*, hash<const char*> > Set;
    hash_set<const char*> Set;

    Set.insert("linux");
    Set.insert("Hello");
    Set.insert("ever");

    ostream_iterator<const char*> output(cout, " ");

    cout << "hash_set: ";
    copy(Set.begin(), Set.end(), output);
    cout << endl;


    return 0;
}

