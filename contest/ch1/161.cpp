/*************************************************************************
	> File Name: 161.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月09日 星期一 21时58分39秒
 ************************************************************************/

#include<iostream>
using namespace std;
const int MAXNUM = 100;

/*find the max value*/
int max(int x, int y, int z)
{
    return (x > y)? ((x > z)? x : x) : ((y > z)? y : z);
}

/*solve the problem*/
void  solve(int n, int *array)
{
    int length = 0;
    int max_length = 0;
    int max_x, i, j, k;

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            for (k = j + 1; k < n; k++){
                max_x = max(array[i], array[j], array[k]);
                length = array[i] + array[j] + array[k];
                if (max_x < length-max_x){
                    if (length > max_length)
                        max_length = length;
                }
            }
    cout << max_length << endl;
}
/*input the data*/
void input_data(int* n, int *arr)
{
    cout << "n = ";
    cin >> *n;
    cout << "a = {";
    for(int i = 0; i < *n; i++){
        cin >> arr[i];
        cin.get();
        cin.get();
    }
}
/*main function*/
int main()
{
    int n;
    int arr[MAXNUM];
    
    input_data(&n, arr);
    solve(n, arr);

    return 0;
}
