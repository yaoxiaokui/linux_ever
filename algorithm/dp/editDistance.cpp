/*************************************************************************
	> File Name: editDistance.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Aug 2016 09:45:27 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int minOperation(string & str1, int len1, string & str2, int len2)
{
    if(len1 == 0)
        return len2;

    if(len2 == 0)
        return len1;

    if(str1[len1-1] == str2[len2-1])
        return minOperation(str1, len1-1, str2, len2-1);
    else{
        return 1 + min(minOperation(str1, len1, str2, len2-1), 
                       minOperation(str1, len1-1, str2, len2),
                       minOperation(str1, len1-1, str2, len2-1));
    }
}

int minOperation(string & str1, string & str2)
{
    int len1 = str1.size();
    int len2 = str2.size();

    int matrix[len1+1][len2+1];


    for(int i = 0; i <= len1; ++i){
        for(int j = 0; j <= len2; ++j){
            if(i == 0)
                matrix[i][j] = j;
            else if(j == 0)
                matrix[i][j] = i;
            else if(str1[i-1] == str2[j-1]){
                matrix[i][j] = matrix[i-1][j-1];    
            }
            else{
                matrix[i][j] = 1 + min(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]);
            }
        }
    }

    return matrix[len1][len2];
}


int main()
{
    string str1;
    string str2;

    while(cin >> str1 >> str2){

        cout << "min operation = " << minOperation(str1, str1.size(), str2, str2.size()) << endl;
        cout << "min operation = " << minOperation(str1, str2) << endl;
    }

    return 0;
}
