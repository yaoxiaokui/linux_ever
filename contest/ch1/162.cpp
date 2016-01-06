/*************************************************************************
	> File Name: 162.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月10日 星期二 21时22分27秒
 ************************************************************************/

#include<iostream>
using namespace std;
/*input the data*/
void input_data(int *length, int *num, int **x)
{
    cout << "L = ";
    cin >> *length;
    cout << "n = ";
    cin >> *num;
    *x = new int[*num];
    cout << "x = {";
    for (int i = 0; i < *num; i++){
        cin >> (*x)[i];
        cin.get();
        cin.get();
    }
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x < y ? x : y;
}
/*solve the problem*/
void solve(int length, int num, int *x)
{
    int min_len = 0;
    int max_len = 0;
    
    for (int i = 0; i < num; i++){
        if (x[i] < length-x[i]){
            min_len = max(x[i], min_len);
            max_len = max(length-x[i], max_len);
        }
        else{
            min_len = max(min_len, length-x[i]);
            max_len = max(max_len, x[i]);
        }
    }
    cout << "min = " << min_len << endl;
    cout << "max = " << max_len << endl;
}
/*main function*/
int main()
{
    int L, n;
    int *x;

    input_data(&L, &n, &x);
    
    solve(L, n, x);

    return 0;
}
