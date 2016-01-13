/*************************************************************************
	> File Name: copy.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 14时07分47秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>
#include <cstring>
using namespace std;


int main()
{
    char A[] = "abcdefgh";
    vector<char> V(A, A+strlen(A));

    list<char> L(V.size());

    copy(V.begin(), V.end(), L.begin());
    cout << "V: ";
    copy(V.begin(), V.end(), ostream_iterator<char>(cout, " "));
    cout << endl;
    cout << "L: ";
    copy(L.begin(), L.end(), ostream_iterator<char>(cout, " "));
    cout << endl;

    list<char> L2;
    copy(V.begin(), V.end(), back_inserter(L2));
    cout << "L2: ";
    copy(L2.begin(), L2.end(), ostream_iterator<char>(cout, " "));
    cout << endl;

    return 0;
}
