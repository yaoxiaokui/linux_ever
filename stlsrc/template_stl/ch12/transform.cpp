/*************************************************************************
	> File Name: transform.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 15时53分56秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <functional>
using namespace std;

template<class T>
struct add{
    add(T value = 0):val(value){}
    T operator()(T & x){
        return x+val;
    } 
    private:
        T val;
};

template<class T>
struct print{
    void operator()(T & x){
        cout << x << " ";
    }
};

int main()
{
    const int N = 7;
    double A[N] = {4, 5, 6, 7, 1, 2, 3};
    vector<double> L(N);


    cout << "A: ";
    for_each(A, A+N, print<double>());
    cout << endl;

    transform(A, A + N, L.begin(), add<double>(3));

    cout << "L: ";
    for_each(L.begin(), L.end(), print<double>());
    cout << endl;
    
    transform(A, A + N, A, negate<double>());

    cout << "-A: ";
    for_each(A, A+N, print<double>());
    cout << endl;

    transform(A, A + N, L.begin(), L.begin(), plus<double>());
    cout << "-A + L: ";
    for_each(L.begin(), L.end(), print<double>());
    cout << endl;

    return 0;
}
