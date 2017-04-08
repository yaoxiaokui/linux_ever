/*************************************************************************
	> File Name: 42reverseSequence.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Jul 2016 10:22:04 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;


//反转单词
void reverse(char *pBegin, char *pEnd)
{
    if(pBegin == NULL || pEnd == NULL)
        return;

    while(pBegin < pEnd){
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;

        ++pBegin;
        --pEnd;
    }
}

//从指定的位置下标开始翻转
void reverseByIndex(char * sequence, int index)
{
    if(sequence == NULL || index >= strlen(sequence))
        return;

    char *pBegin = sequence;
    char *pEnd = sequence;

    while(*pEnd != '\0')
        ++pEnd;

    --pEnd;

    //反转pBegin到index的序列字符
    reverse(pBegin, pBegin + index -1);
    
    //反转index到pEnd的序列字符
    reverse(pBegin + index, pEnd);

    //反转所有的序列字符
    reverse(pBegin, pEnd);

}

//主测试函数
int main()
{

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    cout << "input string: ";
    cin.getline(buffer, 1024);
    
    int index = 0;
    cout << "input index: ";
    cin >> index;

    cout << "buffer: " << buffer << endl;


    reverseByIndex(buffer, index);

    cout << "buffer: " << buffer << endl;

    return 0;
}
