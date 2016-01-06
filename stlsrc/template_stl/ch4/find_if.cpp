/*************************************************************************
	> File Name: unary_even.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月04日 星期一 14时00分01秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool even(int x)
{
    if(x % 2 == 0)
        return true;
    else
        return false;
}

template<class T>
struct int_old{
    bool operator()(T x){
        return x%2 == 1;
    }
};

int main()
{
    vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i+1);
    }
    
    cout << *find_if(v.begin(), v.end(), even) << endl;

    cout << *find_if(v.begin(), v.end(), int_old<int> ()) << endl;
    return 0;
}
