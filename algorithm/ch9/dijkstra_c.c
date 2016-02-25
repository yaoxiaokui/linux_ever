/*************************************************************************
	> File Name: dijkstra_c.c
	> Author: 
	> Mail: 
	> Created Time: 2016年02月25日 星期四 21时46分53秒
 ************************************************************************/

#include <stdio.h>

int main()
{
    int e[10][10], dis[10], book[10], i, j, n, m, t1, t2, t3, u, v, min;
    int inf = 99999999;
    //读入顶点数目和边数目
    scanf("%d %d", &n, &m);

    //初始化
    for(i = 1; i <= n; ++i){
        for(j = 1; j <= n; ++j){
            if(i == j)
                e[i][j] = 0;
            else
                e[i][j] = inf;
        }
    }

    //读入边
    for(i = 1; i <= m; ++i){
        scanf("%d %d %d", &t1, t2, t3);
        e[t1][t2] = t3;
    }

    //初始化dis数组，1号顶点到其它顶点的初始距离
    for(i = 1; i <= n; ++i)
        dis[i] = e[1][i];

    //book数组初始化
    for(i = 1; i <= n; ++i)
        book = 0;

    book[1] = 1;


    return 0;
}
