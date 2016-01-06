/*************************************************************************
	> File Name: sort_card_dfs.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月12日 星期四 09时35分50秒
 ************************************************************************/

#include<iostream>
using namespace std;
const int MAXNUM = 100;

int num;
int box[MAXNUM];
int book[MAXNUM];

void dfs(int step)
{
    if (step == num+1){
        for (int i = 1; i <= num; i++){
            cout << box[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= num; i++){
        if (book[i] == 0){
            box[step] = i;
            book[i] = 1;
            dfs(step+1);
            book[i] = 0;
        }
    }
}

int main()
{
    cout << "Input the n: ";
    cin >> num;
    
    dfs(1);

    return 0;
}
