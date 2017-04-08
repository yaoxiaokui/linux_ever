/*************************************************************************
	> File Name: huiwenstring.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Aug 2016 09:17:41 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int fun(string & str)
{
    string reverseStr;
    for(int i = str.size()-1; i >= 0; --i)
        reverseStr.push_back(str[i]);

    //cout << "reverseStr: " << reverseStr << endl;

    int length = str.size();

    //初始化数组len
    int len[length+1][length+1];
    for(int i = 0; i < length+1; ++i){
        for(int j = 0; j < length+1; ++j)
            len[i][j] = 0;
    }

    //动态规划
    for(int i = 0; i < length; ++i){
        for(int j = 0; j < length; ++j){
            if(str[i] == reverseStr[j]){
                len[i+1][j+1] = len[i][j] + 1;
            }
            else{
                len[i+1][j+1] = max(len[i+1][j],len[i][j+1]);
            }
        }
    }

    return len[length][length];
}

//主函数
int main()
{
    cout << "Input the string: ";
    string str;

    while(getline(cin, str)){
        cout << "string's size() = " << str.size() << endl;

        cout << "max length: " << fun(str) << endl;
    }

    return 0;
}
