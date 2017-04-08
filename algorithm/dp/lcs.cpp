/*************************************************************************
	> File Name: lcs.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Aug 2016 08:57:27 PM CST
 ************************************************************************/


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string & str1, int len1, string & str2, int len2)
{
    if(len1 == 0 || len2 == 0)
        return 0;

    if(str1[len1-1] == str2[len2-1])
        return 1 + lcs(str1, len1-1, str2, len2-1);

    else
        return max(lcs(str1, len1-1, str2, len2), lcs(str1, len1, str2, len2-1));
}


int lcs(string & str1, string & str2)
{
    int len1 = str1.size();
    int len2 = str2.size();

    int matrix[len1+1][len2+1];

    for(int i = 0; i <= len1; ++i){
        for(int j = 0; j <= len2; ++j){
            if(i == 0 || j == 0)
                matrix[i][j] = 0;
            else if(str1[i-1] == str2[j-1])
                matrix[i][j] = 1 + matrix[i-1][j-1];
            else 
                matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j]);
        }
    }

    return matrix[len1][len2];
}



int main()
{
    cout << "str1: ";
    string str1;
    cin >> str1;

    cout << "str2: ";
    string str2;
    cin >> str2;

    int maxLcs = lcs(str1, str1.size(), str2, str2.size());

    cout << "lcs = " << maxLcs << endl;

    maxLcs = lcs(str1, str2);
    cout << "lcs = " << maxLcs << endl;

    return 0;
}
