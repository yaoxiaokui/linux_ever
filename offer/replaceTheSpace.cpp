//length为牛客系统规定字符串输出的最大长度，固定为一个常数


#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;


void replaceSpace(char *str,int length) {
    int spaceCount = 0;
    int strLen = 0;

    while(*(str+strLen) != '\0'){
        if(*(str+strLen) == ' ')
        ++spaceCount;

        ++strLen;
    }

    cout << "space COunt = " << spaceCount << endl;

    //spaceCount等于字符串中空格的数目
    int newLength = strLen + 2*spaceCount;

    cout << "newLength = " << newLength << ", length = " << strLen << endl;
    int index1 = strLen-1;
    int index2 = newLength - 1;

    while(index1 >= 0){
        if(str[index1] != ' ')
            str[index2--] = str[index1--];
        else if(str[index1] == ' '){
            index1--;
            str[index2--] = '0';
            str[index2--] = '2';
            str[index2--] = '%';
        }
    }       

}

int main()
{
    char str[100];
    memset(str, 0, sizeof(str));

    string temp;
    getline(cin, temp);

    strcpy(str, temp.c_str());

    cout << "str = " << str << endl;

    replaceSpace(str, 100);
    cout << str << endl;

    


    return 0;
}
