/*************************************************************************
	> File Name: stringreplace.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 19 Jun 2016 01:21:51 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


int main()
{
    char str[100];
    memset(str, 0, sizeof(str));

    cout << "输入字符串: ";
    gets(str);
    cout << "str: " << str << endl;

    for(int i = 0; i < strlen(str); ++i){
        if(str[i] == ' '){
            //一定要从后向前复制
            for(int j = strlen(str)-1-i; j >= 0; --j){
                str[i+j+2] = str[i+j];
            }

            strncpy(str+i, "%20", 3);
        }
    }
    
    cout << "new str: " << str << endl;

    return 0;
}
