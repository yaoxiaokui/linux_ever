/*************************************************************************
	> File Name: strlen_6_10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月02日 星期三 11时37分03秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;


#define MAX_SIZE 100

int my_strlen(const char *str)
{
    int num = 0;
    
    for(int i = 0; *(str+i) != 0; ++i){
        num++;
    }

    return num;
}

int main()
{
    char buff[MAX_SIZE];
    memset(buff, 0, MAX_SIZE);

    cout << "输入字符串: ";
    cin.getline(buff, MAX_SIZE);
    
    cout <<  "strlen(buff) = " << strlen(buff) << endl;

    int num = 0;

    num = my_strlen(buff);
    cout << "my_strlen(buff) = " << num << endl;

    return 0;
}
