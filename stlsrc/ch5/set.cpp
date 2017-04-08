/*************************************************************************
	> File Name: set.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Jun 2016 05:32:55 PM CST
 ************************************************************************/

#include <vector>
#include <set>
#include <iostream>
using namespace std;


void print(const set<int> & s)
{
    cout << "s: ";
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    int ia[] = {0, 4, 1, 2, 3};
    set<int> s(ia, ia + 5);

    print(s);

    cout << "count of 3 in s = " << s.count(3) << endl; 

    set<int> s1;
    if(s.empty()){
        cout << "s is empty" << endl;
    }
    else{
        cout << "s is not empty" << endl;
    }

    if(s1.empty()){
        cout << "s1 is empty" << endl;
    }
    else{
        cout << "s1 is not empty" << endl;
    }

    pair<set<int>::iterator, set<int>::iterator> ret = s.equal_range(3);
    cout << "*pair.first = " << *ret.first << ", *pair.second = " << *ret.second << endl;


    s.erase(3);
    print(s);
    return 0;
}
