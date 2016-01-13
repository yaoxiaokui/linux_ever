/*************************************************************************
	> File Name: lexicographical_compare.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 13时20分20秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    int A1[] = {3, 1, 4, 1, 5, 9, 3};
    int A2[] = {3, 1, 4, 2, 8, 5, 7};
    int A3[] = {1, 2, 3, 4, 6};
    int A4[] = {1, 2, 3, 4, 5};

    int N1 = sizeof(A1)/sizeof(int);
    int N2 = sizeof(A2)/sizeof(int);
    int N3 = sizeof(A3)/sizeof(int);
    int N4 = sizeof(A4)/sizeof(int);

    cout << "A1: ";
    copy(A1, A1+N1, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "A2: ";
    copy(A2, A2+N2, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "A3: ";
    copy(A3, A3+N3, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "A4: ";
    copy(A4, A4+N4, ostream_iterator<int>(cout, " "));
    cout << endl;

    bool c12 = lexicographical_compare(A1, A1+N1, A2, A2+N2);
    bool c34 = lexicographical_compare(A3, A3+N3, A4, A4+N4);
    
    cout << "A1 < A2 is " << (c12 ? "true" : "false") << endl;
    cout << "A3 < A4 is " << (c34 ? "true" : "false") << endl;


    return 0;
}
