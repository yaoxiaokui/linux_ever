/*************************************************************************
	> File Name: next_permutation.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 10时58分27秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;


int main()
{
    const int N = 4;
    int A[N] = {4, 3, 2, 1};
    do{
        copy(A, A+N, ostream_iterator<int>(cout, " "));
        cout << endl;
    }while(prev_permutation(A, A+N));
    
    return 0;
}
