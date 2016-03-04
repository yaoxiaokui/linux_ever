/*************************************************************************
	> File Name: my_atoi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月03日 星期四 10时35分51秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define BUFFER_SIZE 100

int my_atoi(const char* str)
{
    int len = strlen(str);
    int i = len-1;

    int value = 0;
    //'0' = 48


    while(i >= 0){
        value += (str[i]-48)*pow(10, len-i-1); 
        i--;
    }

    return value;
}

int main()
{
    
    char buff[BUFFER_SIZE];
    memset(buff, 0, BUFFER_SIZE);
    cout << "输入数字字符串: ";
    cin.getline(buff, BUFFER_SIZE);

    int num = my_atoi(buff);

    cout << "int(num) = " << num << endl;

    return 0;
}
