/*************************************************************************
	> File Name: snake_matrix.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月04日 星期一 17时29分57秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define N  1000

class SnckMatrix{
    public:
        SnckMatrix(int n):num(n){
            FillMtrix();
        }
        
        void print();
    private:
        void FillMtrix();
    private:
        int matrix[N][N]; 
        int num;

};

void SnckMatrix::FillMtrix()
{
    int x = 0, y = 0;
    int val = 0;
    int curr_x = num, curr_y = num;
    
    while(x < curr_x && y < curr_y){
        
        //填充一行
        for(int i = y; i < curr_y; ++i){
            matrix[x][i] = ++val;
        }

        for(int i = x+1; i < curr_x; ++i){
            matrix[i][curr_y-1] = ++val;
        }

        for(int i = curr_y-2; i > y; --i){
            matrix[curr_x-1][i] = ++val;
        }

        for(int i = curr_x-1; i > x; --i){
            matrix[i][x] = ++val;
        }

        x++;
        y++;
        curr_x--;
        curr_y--;
    }

}

void SnckMatrix::print()
{
    for(int i = 0; i < num; ++i){
        for(int j = 0; j < num; ++j){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
}

int main()
{
    int size;

    cout << "Input the matrix size: ";
    cin >> size;
    SnckMatrix matrix(size);
    matrix.print();

    return 0;
}
