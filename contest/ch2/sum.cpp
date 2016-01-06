/*************************************************************************
	> File Name: sum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月13日 星期五 20时34分23秒
 ************************************************************************/

#include<iostream>
using namespace std;
const int MAXNUM = 10;
int box[MAXNUM];
int book[MAXNUM];
int count = 0;

void dfs(int step)
{
    if (step == MAXNUM){
        if (box[1]*100+box[2]*10+box[3] + box[4]*100+box[5]*10+box[6] == box[7]*100+box[8]*10+box[9]){
            cout << box[1] << box[2] << box[3] << "+" << box[4] << box[5] << box[6] << "=" 
                << box[7] << box[8] << box[9] << endl;
            count++;
        }
        
        return;
    }

    for (int i = 1; i < MAXNUM; i++){
        if(book[i] == 0){
            box[step] = i;
            book[i] = 1; 
            dfs(step+1);
            book[i] = 0;
        }
    }
    return;
}

int main()
{
    dfs(1);
    
    cout << "There has " << count << " results." << endl;
    return 0;
}
