/*************************************************************************
	> File Name: nth_element.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 21时27分16秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int A[] = {7, 2, 6, 11, 9, 3, 12, 10, 8, 4, 1, 5};
    const int N = sizeof(A)/sizeof(int);

    cout << "A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;


    nth_element(A, A+6, A+N);

    cout << "nth_elemented A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

