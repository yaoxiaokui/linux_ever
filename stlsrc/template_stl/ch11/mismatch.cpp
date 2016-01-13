/*************************************************************************
	> File Name: mismatch.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 12时52分35秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cstring>
using namespace std;

template<class T>
struct equal_nocase{
    bool operator()(T x, T y){
        return tolower(x) == tolower(y);
    }
};

int main()
{
    int A1[] = {3, 1, 4, 1, 5, 9, 3};
    int A2[] = {3, 1, 4, 2, 8, 5, 7};

    const int N = sizeof(A1)/sizeof(int);
    
    cout << "A1 = ";
    copy(A1, A1+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "A2 = ";
    copy(A2, A2+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    pair<int*, int*> result = mismatch(A1, A1+N, A2);
    if(result.first == A1+N)
        cout << "A1 == A2" << endl;
    else{
        cout << "*result.first = " << *result.first << ", *result.second = " << *result.second << endl;
    }

    const char * s1 = "This is a Test";
    const char * s2 = "This is a test";
    int N_char = strlen(s1);

    cout << "s1: ";
    copy(s1, s1+N_char, ostream_iterator<char> (cout, ""));
    cout << endl;

    cout << "s2: ";
    copy(s2, s2+N_char, ostream_iterator<char> (cout, ""));
    cout << endl;

    pair<const char*, const char*> result1 = mismatch(s1, s1 + N_char, s2);
    if(result1.first == s1 + N_char)
        cout << "s1 == s2" << endl;
    else
        cout << "*result1.first = " << *result1.first << ", *result1.second = " << *result1.second << endl;

    result1 = mismatch(s1, s1 + N_char, s2, equal_nocase<char> ());
    if(result1.first == s1 + N_char)
        cout << "s1 == s2" << endl;
    else
        cout << "*result1.first = " << *result1.first << ", *result1.second = " << *result1.second << endl;


    return 0;
}
