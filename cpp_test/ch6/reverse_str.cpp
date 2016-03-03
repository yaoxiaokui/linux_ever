/*************************************************************************
	> File Name: reverse_str.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月03日 星期四 10时19分39秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#define BUFFER_SIZE 100

void reverse(char* str)
{
    int len = strlen(str);
    int i = 0;
    char ch;

    while(i != len/2){
        ch = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = ch;
        i++;
    }   
}

int main()
{
    char buff[BUFFER_SIZE];
    memset(buff, 0, BUFFER_SIZE);

    cout << "输入字符串: ";
    cin.getline(buff, BUFFER_SIZE);

    reverse(buff);
    cout << "反转字符串: " << buff << endl;

    return 0;
}

