/*************************************************************************
	> File Name: findValue.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 19 Jun 2016 09:45:29 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;


const int ROW = 40;
const int COLUMN = 40;


/*****************************************************
*  函数名称：find
*  函数功能: 在二维数组arr中查找值value
*  参数列表: arr是二维数组，row是数组的行数，
*            column是数组的列数, value是要查找的数字
*  参数结果: 找到value，则返回true；否则，则返回false
******************************************************/
bool find(int arr[][COLUMN], int row, int column, int value)
{
    for(int i = 0; i < row; ++i){
        for(int j = column-1; j >= 0; --j){
            if(arr[i][j] == value)
                return true;
            else if(arr[i][j] > value){//如果当前数字大于value，排除该列
                continue;
            }
            else if(arr[i][j] < value){//如果当前数字小于value，排序该行
                break;
            }
        }
    }

    return false;

}


/*****************************************************
*  函数名称：print
*  函数功能: 输出二维数组arr中的元素
*  参数列表: arr是二维数组，row是数组的行数，
*  参数结果: void
******************************************************/
void print(int arr[][COLUMN], int row, int column)
{
    cout << "输出二维数组的元素: " << endl;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


//测试主函数
int main()
{
    int row = 0, column = 0;
    int value;

    cout << "输入数组的行数: ";
    cin >> row;
    cout << "输入数组的列数: ";
    cin >> column;

    cout << "输入要找到的数字: ";
    cin >> value;

    int array[ROW][COLUMN];

    cout << "输入二维数组的元素: " << endl;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            cin >> array[i][j];
        }
    }

    print(array, row, column);


    if(find(array, row, column, value))
        cout << "找到了数字" << value << endl;
    else
        cout << "没有找到数字" << value << endl;
        

    return 0;
}
