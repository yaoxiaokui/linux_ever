/*************************************************************************
	> File Name: random_sample.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 11时37分05秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector> 
using namespace std;


int main()
{
    const int N = 10;
    const int n = 4;

    int A[] = {1, 2, 3, 4, 5, 6, 7 ,8 , 9, 10};
    int B[n];

    random_sample(A, A+N, B, B+n);
    cout << "A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "B:";


    return 0;
}
