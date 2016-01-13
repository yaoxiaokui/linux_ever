/*************************************************************************
	> File Name: remove.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 09时22分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>
using namespace std;

int main()
{
    const int A[9] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    vector<int> V(A, A+9);

    cout << "V: ";
    copy(V.begin(), V.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int>::iterator new_end = remove_if(V.begin(), V.end(), bind2nd(less<int>(), 3));

    cout << "V: ";
    copy(V.begin(), V.end(), ostream_iterator<int>(cout, " "));
    cout << endl;


    cout << "new V: ";
    copy(V.begin(), new_end, ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
