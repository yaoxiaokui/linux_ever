/*************************************************************************
	> File Name: adjacent_find.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月04日 星期一 14时49分18秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
struct two_elem{
    bool operator() (T x, T y){
        return x == y;
    }
};

bool two(int x, int y){
    return x == y;
}

int main()
{
    vector<int> v;
    v.push_back(12);
    v.push_back(1);
    v.push_back(2);
    v.push_back(12);
    v.push_back(12);
    v.push_back(2);
    v.push_back(2);

    cout << *adjacent_find(v.begin(), v.end(), two_elem<int> ()) << endl;
    cout << *adjacent_find(v.begin(), v.end(), two) << endl;
    
    return 0;
}
