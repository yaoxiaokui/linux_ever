/*************************************************************************
	> File Name: moveString.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Aug 2016 09:45:36 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <queue>
using namespace std;

void moveString(string & str)
{
    queue<char> que;
    for(int i = 0; i < str.size(); ++i){
        que.push(str[i]);
    }

    que.push(que.front());
    que.pop();

    str.clear();
    while(!que.empty()){
        str.push_back(que.front());
        que.pop();
    }
}

bool isContain(string & s1, string & s2)
{
    for(int i = 0; i < s2.size(); ++i){
        if(s1[i] != s2[i])
            return false;
    }

    return true;
}

int main()
{
    string s1, s2;

    cout << "input the s1: ";
    cin >> s1;
    cout << "input the s2: ";
    cin >> s2;

    for(int i = 0; i < s1.size(); ++i){
        if(s1[0] == s2[0]){
            if(isContain(s1, s2)){
                cout << "s1 contain s2." << endl;
                return 0;
            }
        } 
        else{
            moveString(s1);
            //cout << "after move the s1: " << s1 << endl;
        }
    }


    cout << "s1 not contain s2." << endl;

    return 0;
}
