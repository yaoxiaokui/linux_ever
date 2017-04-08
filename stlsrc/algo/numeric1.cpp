/*************************************************************************
	> File Name: numeric1.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Aug 2016 09:11:08 AM CST
 ************************************************************************/

#include <iostream>
#include <numeric>
#include <vector>
#include <iterator>
#include <cmath>
using namespace std;


int main()
{
    int ia[5] = {1, 2, 3, 4, 5};

    vector<int> v(ia, ia+5);

    cout << "sum of v = " << accumulate(v.begin(), v.end(), 0) << endl;


    cout << "sum of -v = " << accumulate(v.begin(), v.end(), 0, minus<int>()) << endl;

    cout << "1*1 + 2*2 + 3*3 + 4*4 + 5*5 = ";
    cout << inner_product(v.begin(), v.end(), v.begin(), 10) << endl;

    cout << "1+1 - 2+2 - 3+3 - 4+4 - 5+5 = ";
    cout << inner_product(v.begin(), v.end(), v.begin(), 10, minus<int>(), plus<int>()) << endl;


    ostream_iterator<int> oit(cout, " ");
    partial_sum(v.begin(), v.end(), oit);
    cout << endl;


    partial_sum(v.begin(), v.end(), oit, minus<int>());
    cout << endl;

    adjacent_difference(v.begin(), v.end(), oit);
    cout << endl;

    adjacent_difference(v.begin(), v.end(), oit, plus<int>());
    cout << endl;

    cout << "10^3 = " << pow(10, 3) << endl;


    int n = 3;
    iota(v.begin(), v.end(), n);

    copy(v.begin(), v.end(), oit);
    cout << endl;


    return 0;
}

