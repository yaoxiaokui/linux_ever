/*************************************************************************
	> File Name: inserter.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 25 Mar 2017 12:35:48 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
using namespace std;


int main()
{
    list<int> lst = {1, 2, 3, 4};
    list<int> lst2, lst3;

    cout << "list1: ";
    copy(lst.begin(), lst.end(), ostream_iterator<int> (cout, " "));
    cout << endl;


    copy(lst.begin(), lst.end(), front_inserter(lst2));

    cout << "list2: ";
    copy(lst2.begin(), lst2.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    
    copy(lst.begin(), lst.end(), inserter(lst3, lst3.begin()));
    cout << "list3: ";
    copy(lst3.begin(), lst3.end(), ostream_iterator<int> (cout, " "));
    cout << endl;




    return 0;
}
