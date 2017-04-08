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
    
    //先统计总的空格数目
    int spaceCount = 0;
    int strLen = strlen(str);

    for(int i = 0; i < strLen; ++i){
        if(str[i] == ' ')
            spaceCount++;
    }
    
    //计算替换完所有的空格之后字符串的长度
    int newLen = strLen + 2*spaceCount;

    //newIndexLast指向新字符串的最后一个非空字符
    int newIndexLast = newLen-1;

    //oldIndexLast指向旧字符串的最后一个非空字符
    int oldIndexLast = strLen - 1;

    //拷贝
    for(int i = oldIndexLast; i >= 0; --i){
        if(str[i] == ' '){
            str[newIndexLast--] = '0';
            str[newIndexLast--] = '2';
            str[newIndexLast--] = '%';
        }
        else{
            str[newIndexLast--] = str[i];
        }
    }

    cout << "new str: " << str << endl;

    return 0;
}
