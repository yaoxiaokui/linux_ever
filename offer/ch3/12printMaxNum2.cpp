/*************************************************************************
	> File Name: 12printMaxNum.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jun 2016 09:36:22 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;


//每次将该大数加1
bool Increment(char * number)
{
    bool overFlow = false;
    int carry = 0;//进位

    int strLen = strlen(number);

    for(int i = strLen-1; i >= 0; --i){

        int num = number[i] - '0' + carry;

        if(i == strLen-1)
            num++;

        if(num >= 10){
            
            if(i==0)//此时会溢出
                overFlow = true;
            else{
                num -= 10;
                carry = 1;
                number[i] = num + '0';
            }
        }
        else{
            number[i] = num + '0';
            break;
        }

    }

    return overFlow;
}

//打印数组中表示的数
void PrintNumber(char * number)
{
    int strLen = strlen(number);
    bool beginZero = true;

    for(int i = 0; i < strLen; ++i){
        if(number[i] != '0' && beginZero)
            beginZero = false;

        if(!beginZero)
            cout << number[i];
    }
    cout << " ";
}


void PrintOneToMaxNDigits(int n)
{

    if(n <= 0){
        return;
    }

    char * number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';


    while(!Increment(number)){
        PrintNumber(number);
    }
    cout << endl;

    delete [] number;
}


int main()
{
    cout << "Input the n: ";
    int n;
    cin >> n;

    PrintOneToMaxNDigits(n);

    return 0;
}
