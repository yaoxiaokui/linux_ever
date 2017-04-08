/*************************************************************************
	> File Name: longestIncreSubstring.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Aug 2016 08:30:47 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getLongestSubsequence(vector<int> & v)
{
    int len[v.size()];

    len[0] = 1;

    for(int i = 1; i < v.size(); ++i){
        int max = 0;

        for(int j = i-1; j >= 0; --j){
            if(v[i] > v[j]){
                if(max < len[j] + 1)
                    max = len[j] + 1;
            }
        }

        len[i] = max;
    }

    int max = 0;

    for(int i = 0; i < v.size(); ++i){
        if(max < len[i])
            max = len[i];
    }

    return max;
}


int main()
{

    vector<int> v;
    int value;

    while(cin >> value){
        v.push_back(value);
    }

    cout << "v: ";
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;

    int length = getLongestSubsequence(v);

    cout << "length = " << length << endl;


    return 0;
}
