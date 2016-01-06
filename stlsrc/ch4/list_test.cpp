/*************************************************************************
	> File Name: list_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月20日 星期日 13时52分38秒
 ************************************************************************/

#include<iostream>
#include <list>
#include <algorithm>

using namespace std;


int main()
{
    int i;
    list<int> ilist;
    cout << "size = " << ilist.size() << endl;

    ilist.push_back(0);
    ilist.push_back(1);
    ilist.push_back(2);
    ilist.push_back(3);
    ilist.push_back(4);
    cout << "size = " << ilist.size() << endl;

    list<int>::iterator ite;
    for (ite = ilist.begin(); ite != ilist.end(); ++ite){
        cout << *ite << " ";
    }
    cout << endl;

    ite = find(ilist.begin(), ilist.end(), 3);
    if(ite != ilist.end()){
        ilist.insert(ite, 99);
    }

    cout << "size = " << ilist.size() << endl;
    cout << "*ite = " << *ite << endl;
    for (ite = ilist.begin(); ite != ilist.end(); ++ite){
        cout << *ite << " ";
    }
    cout << endl;





    return 0;
}
