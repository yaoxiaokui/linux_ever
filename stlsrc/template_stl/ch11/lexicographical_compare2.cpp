/*************************************************************************
	> File Name: lexicographical_compare.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 13时20分20秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstring>
using namespace std;

template<class T>
struct comp_nocase{
    bool operator()(T x, T y){
        return tolower(x) < tolower(y);
    }
};

int main()
{
    const char * s1 = "abc";
    const char * s2 = "ABC";
    const char * s3 = "abcDEF";


    const int N1 = strlen(s1);
    const int N2 = strlen(s2);
    const int N3 = strlen(s3);

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;

    bool c12 = lexicographical_compare(s1, s1+N1, s2, s2+N2);
    bool c12_nocase = lexicographical_compare(s1, s1+N1, s2, s2+N2, comp_nocase<char>());
    
    cout << "s1 < s2 is " << (c12 ? "true" : "false") << endl;
    cout << "s1 < s2(nocase) is " << (c12_nocase ? "true" : "false") << endl;

    bool c23 = lexicographical_compare(s2, s2+N2, s3, s3+N3);
    bool c23_nocase = lexicographical_compare(s2, s2+N2, s3, s3+N3, comp_nocase<char>());
    
    cout << "s2 < s3 is " << (c23 ? "true" : "false") << endl;
    cout << "s2 < s3(nocase) is " << (c23_nocase ? "true" : "false") << endl;

    return 0;
}
