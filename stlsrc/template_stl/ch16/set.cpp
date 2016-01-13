/*************************************************************************
	> File Name: set.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月13日 星期三 14时44分51秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
#include <functional>
#include <cstring>
using namespace std;


struct less_str{

    bool operator()(const char * s1, const char * s2) const{
        return strcmp(s1, s2) < 0;
    }
};

int main()
{
    const int N = 6;
    const char * a[N] = {"linux", "ever", "time", "set", "author", "mail"};
    const char * b[N] = {"file", "name", "set", "create", "time", "mail"};

    set<const char *, less_str> A(a, a+N);
    set<const char *, less_str> B(b, b+N);
    set<const char *, less_str> C;

    cout << "set A: ";
    copy(A.begin(), A.end(), ostream_iterator<const char *>(cout, " "));
    cout << endl;

    cout << "set B: ";
    copy(B.begin(), B.end(), ostream_iterator<const char *>(cout, " "));
    cout << endl;

    cout << "union of A and B: ";
    set_union(A.begin(), A.end(), B.begin(), B.end(), ostream_iterator<const char *>(cout ," "), less_str());
    cout << endl;


    return 0;
}

