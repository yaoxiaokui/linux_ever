/*************************************************************************
	> File Name: find.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月19日 星期六 15时42分04秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <deque>
#include <string>
#include <memory>
using namespace std;

void test_auto_ptr()
{
    auto_ptr<string> ps(new string("auto_ptr ...."));

    cout << "*auto_ptr is: " << *ps << endl;
    cout << "string size is : " << ps->size() << endl;
}
int main()
{
    const int arraySize = 7;
    int ia[arraySize] = {0, 1, 2, 3, 4, 5, 6};

    test_auto_ptr();

    vector<int> ivect(ia, ia+arraySize);
    list<int> ilist(ia, ia+arraySize);
    deque<int> ideque(ia, ia+arraySize);

    vector<int>::iterator it1 = find(ivect.begin(), ivect.end(), 4);
    if(it1 == ivect.end()){
        cout << "4 not find.\n";
    }
    else{
        cout << "4 find.." << *it1 << endl;
    }

    list<int>::iterator it2 = find(ilist.begin(), ilist.end(), 6);
    if(it2 == ilist.end()){
        cout << "6 not find..\n";
    }
    else{
        cout << "6 find.." << *it2 << endl;
    }

    deque<int>::iterator it3 = find(ideque.begin(), ideque.end(), 8);
    if(it3 == ideque.end()){
        cout << "8 not find.." << endl;
    }
    else{
        cout << "8 find.." << *it3 << endl;
    }

    return 0;
}
