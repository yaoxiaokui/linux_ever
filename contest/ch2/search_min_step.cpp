/*************************************************************************
	> File Name: search_min_step.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月13日 星期五 21时49分41秒
 ************************************************************************/

#include<iostream>

using namespace std;

const int MAX_X = 50;
const int MAX_Y = 50;
int min_step = 10000;
int my_x, my_y;
int map[MAX_X][MAX_Y];
int book[MAX_X][MAX_Y];
int start_x, start_y;
int dest_x, dest_y;

void dfs(int x, int y, int step)
{
    /*up, right, down, left*/
    int next[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    int tx, ty;

    if (x == dest_x && y == dest_y){
        if (step < min_step)
            min_step = step;
        return;
    }

    for (int i = 0; i < 4; i++){
        tx = x + next[i][0];
        ty = y + next[i][1];
        if (tx > my_x || ty > my_y || tx < 0 || ty < 0)
            continue;

        if (map[tx][ty] == 0 && book[tx][ty] == 0){
            book[tx][ty] = 1;
            dfs(tx, ty, step+1);
            book[tx][ty] = 0;
        }
    }

}
void input_map_info()
{
    cout << "input the max x:";
    cin >> my_x;
    cout << "input the max y:";
    cin >> my_y;

    cout << "input the map information:\n";
    for (int i = 1; i <= my_x; i++){
        for (int j = 1; j <= my_y; j++){
            cin >> map[i][j];
        }
    }
}

int main()
{
    input_map_info();

    cout << "input the source location:";
    cin >> start_x >> start_y;
    cout << "input the destat location:";
    cin >> dest_x >> dest_y;

    book[start_x][start_y] = 1;
    dfs(start_x, start_y, 0);
    
    cout << "min_step = " << min_step << endl;

    return 0;
}
