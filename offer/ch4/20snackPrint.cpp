/*************************************************************************
	> File Name: 20snackPrint.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Jun 2016 04:00:12 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;



const int N = 100;


void printSnackMatrix(int matrix[][N], int num)
{
    int x = 0, y = 0;
    int current_x = num-1;//行
    int current_y = num-1;//列

    while(x <= current_x && y <= current_y){
        //输出最上面的行
        for(int i = y; i <= current_y; ++i){
            cout << matrix[x][i] << " ";
        }

        x++;//移动到下一行

        //输出最右边的列
        for(int i = x; i <= current_x; ++i){
            cout << matrix[i][current_y] << " ";
        }

        current_y--;//向前移动一列

        //输出最下面的行
        for(int i = current_y; i >= y; --i){
            cout << matrix[current_x][i] << " ";
        }

        current_x--;//移动到上一行

        //输出最左边的列
        for(int i = current_x; i >= x; --i){
            cout << matrix[i][y] << " ";
        }

        y++;
    }

    cout << endl;
}


int main()
{
    int matrix[N][N];

    int num;
    cout << "输入矩阵的行数: ";
    cin >> num;

    //初始化矩阵
    for(int i = 0; i < num; ++i){
        for(int j = 0; j < num; ++j){
            matrix[i][j] = i*num + j + 1;
        }
    }


    //输出
    cout << "正常输出: " << endl;
    for(int i = 0; i < num; ++i){
        for(int j = 0; j < num; ++j){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }


    cout << "顺时针输出: " << endl;
    printSnackMatrix(matrix, num);

    return 0;
}
