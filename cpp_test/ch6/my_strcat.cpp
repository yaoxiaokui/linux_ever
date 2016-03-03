/*************************************************************************
	> File Name: my_strcat.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月03日 星期四 09时59分18秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#define BUFFER_SIZE 100

char* my_strcat(const char* str1, const char* str2)
{
    int len = strlen(str1) + strlen(str2) + 1;
    char* dest = new char[len];
   
    strcpy(dest, str1);

    int i = strlen(str1);
    int j = 0;

    while(*(str2+j) != 0){
        *(dest+i+j) = *(str2+j);
        j++;
    }
    *(dest+i+j) = 0;

    return dest;
}

int main()
{
    
    char str1[BUFFER_SIZE];
    char str2[BUFFER_SIZE];

    memset(str1, 0, BUFFER_SIZE);
    memset(str2, 0, BUFFER_SIZE);

    cout << "输入str1: ";
    cin.getline(str1, BUFFER_SIZE);
    cout << "输入str2: ";
    cin.getline(str2, BUFFER_SIZE);

    char* dest = my_strcat(str1, str2);

    cout << "str1 + str2 = " << dest << endl;

    delete [] dest; 
    

    return 0;
}
