/*************************************************************************
	> File Name: map.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月19日 星期四 21时51分20秒
 ************************************************************************/

#include<iostream>
#include <deque>
#include <queue>
using namespace std;

const int INF = 100000;
typedef pair<int, int> P;
const int MAX_N = 100;
const int MAX_M = 100;

char map[MAX_N][MAX_M];
int d[MAX_N][MAX_M];

int sx, sy;
int gx, gy;
int N, M;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void input_data()
{
    cout << "N: ";
    cin >> N;
    cout << "M: ";
    cin >> M;

    cout << "input the map:" << endl;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            cin >> map[i][j];
        }
    }

    cout << "input the start_x and start_y: ";
    cin >> sx >> sy;

    cout << "input the des_x and des_y: ";
    cin >> gx >> gy;
}

int dfs()
{
    queue<P> que;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            d[i][j] = INF;
        }
        
    }

    que.push(P(sx, sy));
    d[sx][sy] = 0;
    
    while(que.size()){
        P p = que.front();
        que.pop();

        if (p.first == gx && p.second == gy)
            break;
        
        for (int i = 0; i < 4; ++i){
            int nx = p.first + dx[i], ny = p.second + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M && map[nx][ny] != '#' && d[nx][ny] == INF){
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }

    return d[gx][gy];
}
   

void solve()
{
    int min_step = 0;

    min_step = dfs();

    cout << "min_step is " << min_step << endl;
}

int main()
{
    input_data();

    solve();
}

