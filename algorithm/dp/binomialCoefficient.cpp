/*************************************************************************
	> File Name: binomialCoefficient.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Aug 2016 08:50:19 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

//递归实现，其实就是动态规划
int binomialCoefficient(int n, int k)
{
    if(k == 0)
        return 1;

    if(n == k)
        return 1;

    return binomialCoefficient(n-1, k-1) + binomialCoefficient(n-1, k);
}

//求二项式系数
int binomialCoefficient2(int n, int k)
{
    //0---n共有n+1项，0---k共有k+1项,所以数组大小为[n+1][k+1]
    int result[n+1][k+1];
    memset(result, 0, sizeof(result));
    

    //将递归变为循环
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= min(i, k); ++j){
            if(i==j || j==0)
                result[i][j] = 1;
            else 
                result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
    }

    return result[n][k];
}

//主函数
int main()
{
    cout << "input the n:";
    int n;
    cin >> n;

    cout << "input the k: ";
    int k;
    cin >> k;

    int result = binomialCoefficient(n, k);
    cout << "c(" << n << ", " << k << ") = " << result << endl;

    result = binomialCoefficient2(n, k);
    cout << "c(" << n << ", " << k << ") = " << result << endl;


    return 0;
}
