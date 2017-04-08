/*************************************************************************
	> File Name: mapsearch.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Aug 2016 12:44:57 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_X = 100;
const int MAX_Y = 100;

int map[MAX_X][MAX_Y];
int book[MAX_X][MAX_Y];

int minLen = 0x7FFFFFFF;
int x_len, y_len;

vector<vector<int> > path;
//右，下，左,上
int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void printPath(vector<vector<int> > & path)
{
    for(int i = 0; i < path.size(); ++i){
        cout << "(" << path[i][0] << "," << path[i][1] << ")" << "-->";
    }
    cout << endl;
}

void dfs(int dest_x, int dest_y, int x, int y, int count, vector<vector<int> > & path)
{
    if(x == dest_x && y==dest_y){
        //cout << "minLen = " << minLen << ", count = " << count << endl;
        printPath(path);

        if(minLen > count)
            minLen = count;
        return;
    }

    for(int i = 0; i < 4; ++i){
        int next_x = x+next[i][0];
        int next_y = y+next[i][1];

        if(next_x<1 || next_y<1 || next_x>x_len || next_y > y_len)
            continue;

        if(book[next_x][next_y]==0 && map[next_x][next_y]==0){
            //添加该路径结点
            vector<int> temp;
            temp.push_back(next_x);
            temp.push_back(next_y);
            path.push_back(temp);

            //标记该结点已经走过
            book[next_x][next_y] = 1;
            dfs(dest_x, dest_y, next_x, next_y, count+1, path);
            //标记该结点没有走过
            book[next_x][next_y] = 0;
            //弹出该路径结点
            path.pop_back();
        }
    }

}

int main()
{
    memset(book, 0, sizeof(book));

    int x, y;
    int dest_x, dest_y;
    int count = 0;

    cout << "input the x, y: ";
    cin >> x;
    cin >> y;

    cout << "input the dest_x, dest_y: ";
    cin >> dest_x;
    cin >> dest_y;

    cout << "input the x_len, y_len: ";
    cin >> x_len;
    cin >> y_len;


    cout << "input the map: " << endl;
    for(int i = 1; i <= x_len; ++i){
        for(int j = 1; j <= y_len; ++j){
            cin >> map[i][j];
        }
    }

    book[x][y] = 1;
    vector<int> temp;
    temp.push_back(x);
    temp.push_back(y);
    path.push_back(temp);

    dfs(dest_x, dest_y, x, y, 0, path);

    cout << "minLen = " << minLen << endl;

    return 0;
}
