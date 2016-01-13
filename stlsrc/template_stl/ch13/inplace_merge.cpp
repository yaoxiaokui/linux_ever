/*************************************************************************
	> File Name: merge.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 22时38分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int A1[] = {1, 3, 5, 7, 2, 4, 6, 8};

    const int N1 = sizeof(A1)/sizeof(int);


    cout << "A1: ";
    copy(A1, A1+N1, ostream_iterator<int>(cout, " "));
    cout << endl;

    inplace_merge(A1, A1+4, A1+N1);
    
    cout << "merged of A1 and A2: ";
    copy(A1, A1+N1, ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

