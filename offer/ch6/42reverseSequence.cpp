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

//反转语句
void reverseSequence(char * sequence)
{
    if(sequence == NULL)
        return;

    char *pBegin = sequence;
    char *pEnd = sequence;

    while(*pEnd != '\0')
        ++pEnd;

    --pEnd;
    
    //反转所有的序列字符
    reverse(pBegin, pEnd);

    //再反转每个单词
    
    pBegin = pEnd = sequence;

    while(*pBegin != '\0'){
        if(*pBegin == ' '){
            pBegin++;
            pEnd++;
        }
        else if(*pEnd == ' ' || *pEnd == '\0'){
            reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else
            pEnd++;
    }
}

int main()
{

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    cin.getline(buffer, 1024);

    cout << "buffer: " << buffer << endl;

    reverseSequence(buffer);

    cout << "buffer: " << buffer << endl;

    return 0;
}
