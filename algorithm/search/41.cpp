/*************************************************************************
	> File Name: 41.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Aug 2016 10:58:24 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;

void dfs2(int *book, int * box, int step)
{
    if(step == n+1){
        if(box[1]*100+box[2]*10+box[3] + box[4]*100+box[5]*10+box[6] == box[7]*100+box[8]*10+box[9]){
            for(int i = 1; i <= n; ++i){
                cout << box[i] << " ";
            }
            cout << endl;
            return;
        }
    }

    for(int i = 1; i <= n; ++i){
        if(book[i] == 0){
            box[step] = i; 
            book[i] = 1;

            dfs2(book, box, step+1);
            book[i] = 0;
        }
    }

    return;
}
void dfs(int *book, int * box, int step)
{
    if(step == n+1){
        for(int i = 1; i <= n; ++i){
            cout << box[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = 1; i <= n; ++i){
        if(book[i] == 0){
            box[step] = i; 
            book[i] = 1;

            dfs(book, box, step+1);
            book[i] = 0;
        }
    }

    return;
}

int main()
{
    cout << "input the n: ";
    cin >> n;

    int box[n+1];
    int book[n+1];
    //初始化为0
    for(int i =0 ; i <= n; ++i)
        book[i] = 0;


    //dfs(book, box, 1);
    dfs2(book, box, 1);

    return 0;
}
