/*************************************************************************
	> File Name: flipChess.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Aug 2016 09:53:53 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<vector<int> > A, f;
    int value;

    cout << "input the A: ";
    for(int i = 0; i < 4; ++i){
        vector<int> temp;
        for(int j =0; j < 4; ++j){
            cin >> value;
            temp.push_back(value);
        }

        A.push_back(temp);
    }

    cout << "input the f: ";




    return 0;
}
