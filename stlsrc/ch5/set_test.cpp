/*************************************************************************
	> File Name: set_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月24日 星期四 17时16分07秒
 ************************************************************************/

#include<iostream>
#include <set>
#include <algorithm>

using namespace std;


int main()
{
    int i;
    int ia[5] = {0, 1, 2, 3, 4};
    set<int> iset(ia, ia+5);

    cout << "size is " << iset.size() << endl;
    cout << "3 count is " << iset.count(3) << endl;

    iset.insert(3);
    cout << "size is " << iset.size() << endl;
    cout << "3 count is " << iset.count(3) << endl;

    iset.insert(5);
    cout << "size is " << iset.size() << endl;
    cout << "3 count is " << iset.count(3) << endl;

    iset.erase(1);
    cout << "size is " << iset.size() << endl;
    cout << "3 count is " << iset.count(3) << endl;
    cout << "1 count is " << iset.count(1) << endl;

    set<int>::iterator it1 = iset.begin();
    set<int>::iterator it2 = iset.end();
    cout << "set is :";
    for( ; it1 != it2; ++it1 ){
        cout << *it1 << " ";
    }
    cout << endl;

    it1 = find(iset.begin(), iset.end(), 3);
    if(it1 == iset.end()){
        cout << "3 not find" << endl;
    }
    else{
        cout << "3 find" << endl;
    }

    it1 = find(iset.begin(), iset.end(), 1);
    if(it1 == iset.end()){
        cout << "1 not find" << endl;
    }
    else{
        cout << "1 find" << endl;
    }

    it1 = iset.find(3);
    if(it1 == iset.end()){
        cout << "3 not find" << endl;
    }
    else{
        cout << "3 find" << endl;
    }

    it1 = iset.find(1);
    if(it1 == iset.end()){
        cout << "1 not find" << endl;
    }
    else{
        cout << "1 find" << endl;
    }

    return 0;
}
