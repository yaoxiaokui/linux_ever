/*************************************************************************
	> File Name: equal.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 12时28分05秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

template<class T>
struct caseInsentive{
    bool operator()(T x, T y){
        return tolower(x) == tolower(y);
    }
};

int main()
{
    int A1[] = {3, 1, 4, 1, 5, 9, 3};
    int A2[] = {3, 1, 4, 2, 8, 5, 7};
    int A3[] = {3, 1, 4, 1, 5, 9, 3};

    const int N = sizeof(A1)/sizeof(int);

    cout << "A1: ";
    copy(A1, A1+N, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "A2: ";
    copy(A2, A2+N, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "A3: ";
    copy(A3, A3+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    if(equal(A1, A1+N, A2))
        cout << "A1 == A2" << endl;
    else
        cout << "A1 != A2" << endl;

    if(equal(A1, A1+N, A3))
        cout << "A1 == A3" << endl;
    else
        cout << "A1 != A3" << endl;


    char c1[] = {'a', 'b', 'v', 'g'};
    char c2[] = {'a', 'B', 'V', 'g'};
    const int N_char = sizeof(c1)/sizeof(char);
    
    cout << "c1: ";
    copy(c1, c1+N_char, ostream_iterator<char>(cout, " "));
    cout << endl;
    cout << "c2: ";
    copy(c2, c2+N_char, ostream_iterator<char>(cout, " "));
    cout << endl;

    if(equal(c1, c1+N_char, c2))
        cout << "c1 == c2, 区分大小写" << endl;
    else
        cout << "c1 != c2, 区分大小写" << endl;

    if(equal(c1, c1+N_char, c2, caseInsentive<char>()))
        cout << "c1 == c2, 不区分大小写" << endl;
    else
        cout << "c1 != c2, 不区分大小写" << endl;
    
    return 0;
}
