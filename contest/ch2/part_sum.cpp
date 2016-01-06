/*************************************************************************
	> File Name: part_sum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月11日 星期三 20时16分46秒
 ************************************************************************/

#include<iostream>
using namespace std;
const int MAXNUM = 20;

int arr[MAXNUM];
int n, k;

void input_data(int *n, int *k, int *arr)
{
    cout << "n = ";
    cin >> *n;
    cout << "a = {";
    for (int i = 0; i < *n; i++){
        cin >> arr[i];
        cin.get();
        cin.get();
    }
    cout << "k = ";
    cin >> *k;
}

bool dfs(int i, int sum)
{
    if (i == n) return sum == k;
    if (dfs(i+1, sum)) return true;
    if (dfs(i+1, sum+arr[i])) return true;

    return false;
}

void solve()
{
    if (dfs(0, 0))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;    
}

int main()
{
    input_data(&n, &k, arr);

    solve();

    return 0;
}
