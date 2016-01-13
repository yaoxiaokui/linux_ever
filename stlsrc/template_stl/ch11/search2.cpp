/*************************************************************************
	> File Name: search.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月09日 星期六 11时31分13秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

template<class T>
struct myRule{
    myRule(T n):N(n){}
    bool operator()(T x, T y) const {
        return (x-y)%N == 0;
    }
    int N;
};


int main()
{
    int A[] = {22, 23, 45, 67, 61, 82, 13, 21};
    int sub[] = {1, 2, 3};

    int * result = search(A, A+8, sub, sub+3, myRule<int> (10));
    if(result == A+8)
        cout << "find no element" << endl;
    else{
        cout << "result is: ";
        for (int i = 0; i < 3; i++)
            cout << *(result+i) << " ";
        cout << endl;
    }

    return 0;
}

