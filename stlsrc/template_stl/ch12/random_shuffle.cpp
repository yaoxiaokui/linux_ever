/*************************************************************************
	> File Name: random_shuffle.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 11时31分43秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;


int myrand(int i)
{
    return rand()%i;
}
int main()
{
    const int N = 8;
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};

    cout << "A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;

    random_shuffle(A, A + N);
    cout << "random_shuffleed A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;


    random_shuffle(A, A + N, myrand);
    cout << "random_shuffleed rand A: ";
    copy(A, A+N, ostream_iterator<int>(cout, " "));
    cout << endl;


    return 0;
}

