/*************************************************************************
	> File Name: lakeCounting.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月18日 星期三 21时10分13秒
 ************************************************************************/

#include<iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

char map[MAX_N][MAX_M];
int n, m;

void input_data()
{
    cout << "input the n: ";
    cin >> n;
    cout << "input the m: ";
    cin >> m;
    cout << "input the map:" << endl;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> map[i][j];
        }
    }
}

void output_data()
{
    cout << "n = " << n << ", m = " << m << endl;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(int x, int y)
{
    map[x][y] = '.';

    int tx, ty;

    for (int i = -1; i <= 1; ++i){
        for (int j = -1; j <= 1; ++j){
            tx = x + i;
            ty = y + j;
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && map[tx][ty] == 'w'){
                dfs(tx, ty);
            }
        }
    }

    return;
}

void solve()
{
    int num = 0;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (map[i][j] == 'w'){
                dfs(i, j);
                num++;
            }
        }
    }

    cout << "the num is " << num << endl;
}

int main()
{
    input_data();

   //output_data();
    solve();

    return 0;
}
