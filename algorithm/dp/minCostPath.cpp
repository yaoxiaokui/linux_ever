/*************************************************************************
	> File Name: minCostPath.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 15 Aug 2016 10:05:25 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;


const int num = 3;

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}


int minCostPath(int matrix[][num], int src_x, int src_y, int dest_x, int dest_y)
{
    if(dest_x < src_x || dest_y < src_y)
        return 0x7FFFFFFF;
    else if(dest_x == src_x && dest_y == src_y)
        return matrix[dest_x][dest_y];
    else{
        return matrix[dest_x][dest_y] + min(minCostPath(matrix, src_x, src_y, dest_x-1, dest_y), 
                                          minCostPath(matrix, src_x, src_y, dest_x, dest_y-1), 
                                          minCostPath(matrix, src_x, src_y, dest_x-1, dest_y-1));
    }
}

int minCostPath2(int matrix[][num], int src_x, int src_y, int dest_x, int dest_y)
{
    int cost[num][num];

    cost[0][0] = matrix[0][0];

    //初始化第一列
    for(int i = 1; i <=dest_x ; ++i){
        cost[i][0] = cost[i-1][0] + matrix[i][0];
    }

    //初始化第一行
    for(int j = 1; j <= dest_y; ++j){
        cost[0][j] = cost[0][j-1] + matrix[0][j];
    }


    for(int i = 1; i <= dest_x; ++i){
        for(int j = 1; j <= dest_y; ++j){
            cost[i][j] = matrix[i][j] + min(cost[i-1][j], cost[i][j-1], cost[i-1][j-1]);
        }
    }
    
    return cost[dest_x][dest_y];
}

int main()
{
    int src_x, src_y;
    int dest_x, dest_y;
    int matrix[num][num];// = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};

    while(1){

        cout << "输入矩阵的元素: " << endl;

        for(int i = 0; i < num; ++i){
            for(int j = 0; j < num; ++j){
                cin >> matrix[i][j];
            }
        }

        cout << "Input the src: ";
        cin >> src_x >> src_y;
        cout << "Input the dest: ";
        cin >> dest_x >> dest_y;

        int minCost = minCostPath(matrix, src_x, src_y, dest_x, dest_y);
        cout << "最小路径花费是: " << minCost << endl;

        minCost = minCostPath2(matrix, src_x, src_y, dest_x, dest_y);
        cout << "最小路径花费是: " << minCost << endl;
    }





    return 0;
}
