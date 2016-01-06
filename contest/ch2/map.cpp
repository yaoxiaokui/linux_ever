/*************************************************************************
	> File Name: map.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月19日 星期四 21时51分20秒
 ************************************************************************/

#include<iostream>
#include <deque>

using namespace std;

const int MAXNUM = 999999;
const int MAX_N = 100;
const int MAX_M = 100;

int N, M;
char map[MAX_N][MAX_M];

int start_x, start_y;
int des_x, des_y;

typedef pair<int, int> Pair;
deque<Pair> node;
int node_step[MAX_N][MAX_M];

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
    cin >> start_x >> start_y;

    cout << "input the des_x and des_y: ";
    cin >> des_x >> des_y;

}

int dfs()
{
    /*up, right, down, left*/
    int next[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            node_step[i][j] = MAXNUM;
        }
    }
   
    int tx, ty;

    node.push_back(Pair(start_x, start_y));
    node_step[start_x][start_y] = 0;

    while(node.size()){
        Pair p = node.front();
        node.pop_front();
        if (p.first == des_x && p.second == des_y){
            break;
        }
        cout << "p.first: " << p.first << ", p.second: " << p.second << endl;
        for (int i = 0; i < 4; ++i){
            tx = p.first + next[i][0];
            ty = p.second + next[i][1];
            if (tx >= 0 && tx < N && ty >= 0 && ty < M && map[tx][ty] != '#' && node_step[tx][ty] == MAXNUM){
                node.push_back(Pair(tx, ty));
                node_step[tx][ty] = node_step[p.first][p.second] + 1;
            }
        } 
    }

    return node_step[des_x][des_y];
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

