/*************************************************************************
	> File Name: multiset.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Mar 2017 09:59:14 AM CST
 ************************************************************************/

#include <iostream>
#include <set>
#include <vector>
using namespace std;


int main()
{
    vector<int> ivec;
    for(vector<int>::size_type i = 0; i < 10; ++i){
        ivec.push_back(i);
        ivec.push_back(i);
    }

    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());

    cout << "ivec.size() = " << ivec.size() << endl;
    cout << "iset.size() = " << iset.size() << endl;
    cout << "miset.size() = " << miset.size() << endl;



    return 0;
}
