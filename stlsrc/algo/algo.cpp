/*************************************************************************
	> File Name: algo.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Aug 2016 10:04:12 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template<typename T>
class display{
public:
    void operator()(const T &x) const{
        cout << x << " ";
    }

};

int main()
{
    int ia[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> iv1(ia, ia+5);
    vector<int> iv2(ia, ia+9);

    cout << "iv1: ";
    copy(iv1.begin(), iv1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "iv2: ";
    for_each(iv2.begin(), iv2.end(), display<int>());
    cout << endl;


    pair<vector<int>::iterator, vector<int>::iterator> result = mismatch(iv1.begin(), iv1.end(), iv2.begin());
    if(result.first == iv1.end()){
        cout << "result.first == iv1.end" << endl;
    }
    else
        cout << *(result.first) << endl;


    cout << *(mismatch(iv1.begin(), iv1.end(), iv2.begin()).second) << endl;


    cout << equal(iv1.begin(), iv1.end(), iv2.begin()) << endl;
    cout << equal(iv1.begin(), iv1.end(), &iv2[2]) << endl;

    cout << "after fill 9: ";
    fill(iv1.begin(), iv1.end(), 9);

    cout << "iv1: ";
    for_each(iv1.begin(), iv1.end(), display<int>());
    cout << endl;

    fill_n(iv1.begin(), 3, 7);
    cout << "iv1: ";
    for_each(iv1.begin(), iv1.end(), display<int>());
    cout << endl;

    return 0;
}

