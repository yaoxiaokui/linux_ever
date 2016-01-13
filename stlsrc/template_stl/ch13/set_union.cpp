/*************************************************************************
	> File Name: set_union.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月12日 星期二 10时08分27秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

bool less_nocase(char x, char y)
{
    return tolower(x) < tolower(y);
}

int main()
{
    int A1[] = {1, 3, 5, 7, 9, 11};
    int A2[] = {1, 1, 2, 3, 5, 8, 13};

    char A3[] = {'a', 'b', 'B', 'B', 'f', 'H'};
    char A4[] = {'A', 'B', 'b', 'C', 'D', 'F', 'F', 'h', 'h'};

    const int N1 = sizeof(A1)/sizeof(int);
    const int N2 = sizeof(A2)/sizeof(int);

    const int N3 = sizeof(A3);
    const int N4 = sizeof(A4);

    cout << "A1: ";
    copy(A1, A1+N1, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "A2: ";
    copy(A2, A2+N2, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "A3: ";
    copy(A3, A3+N3, ostream_iterator<char>(cout, " "));
    cout << endl;

    cout << "A4: ";
    copy(A4, A4+N4, ostream_iterator<char>(cout, " "));
    cout << endl;

    cout << "union of A1 and A2: ";
    set_union(A1, A1+N1, A2, A2+N2, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "union of A3 and A4: ";
    set_union(A3, A3+N3, A4, A4+N4, ostream_iterator<char>(cout, " "), less_nocase);
    cout << endl;

    return 0;
}

