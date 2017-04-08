/*************************************************************************
	> File Name: yanghuisanjiao.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Aug 2016 02:37:23 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


//递归版本
int f(int m, int n)
{
    if(m == 1)
        return n;
    if(n == 1)
        return m;

    return f(m-1, n) + f(m, n-1);
}


//循环版本
int f2(int m, int n)
{
    int arr[m+1][n+1];

    for(int i = 0; i < n+1; ++i)
        arr[1][i] = i;
    for(int i = 0; i < m+1; ++i)
        arr[i][1] = i;

    for(int i = 2; i < m+1; ++i){
        for(int j = 2; j < n+1; ++j){
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    return arr[m][n];
}

int main()
{
    int m, n;
    cout << "input the m and n: ";
    cin >> m >> n;

    cout << "f(m, n) = " << f(m, n) << endl;
    cout << "f(m, n) = " << f2(m, n) << endl;


    return 0;
}
