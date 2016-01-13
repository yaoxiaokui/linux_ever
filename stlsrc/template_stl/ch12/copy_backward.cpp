/*************************************************************************
	> File Name: copy_backward.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 14时20分10秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int A[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    cout << "A: ";
    copy(A, A+15, ostream_iterator<int>(cout, " "));
    cout << endl;

    copy_backward(A, A+10, A+15);

    cout << "A: ";
    copy(A, A+15, ostream_iterator<int>(cout, " "));
    cout << endl;


    return 0;
}
