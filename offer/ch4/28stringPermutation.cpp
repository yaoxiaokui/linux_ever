/*************************************************************************
	> File Name: 28stringPermutation.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Jun 2016 09:03:12 AM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

void permutation(char * str, char * pBegin)
{
    if(*pBegin == '\0')
        cout << str << endl;
    else{
        for(char * pch = pBegin; *pch != '\0'; ++pch){
            //交换第一个字符和后面的字符
            char temp = *pch;
            *pch = *pBegin;
            *pBegin = temp;

            permutation(str, pBegin+1);

            //再将刚才的交换恢复过来
            temp = *pch;
            *pch = *pBegin;
            *pBegin = temp;
        }
    }
}


void permutation(char * str)
{
    if(str == NULL)
        return;

    permutation(str, str);
}


int main()
{
    char str[100];
    memset(str, 0, 100);


    cout << "Input the str: ";
    cin >> str;

    cout << "排列: " << endl;

    permutation(str);

    return 0;
}
