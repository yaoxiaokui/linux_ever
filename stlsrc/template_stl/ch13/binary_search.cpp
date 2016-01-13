/*************************************************************************
	> File Name: binary_search.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 21时45分13秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int A[] = {1, 2, 3, 3, 3, 5, 8};
    const int N = sizeof(A)/sizeof(int);

    cout << "A: ";
    copy(A, A+N, ostream_iterator<int> (cout, " "));
    cout << endl;

    for(int i = 1; i <= 10; ++i){
        cout << "search for " << i << ": " << (binary_search(A, A+N, i)? "present":"not present") << endl;
    }

    return 0;
}

