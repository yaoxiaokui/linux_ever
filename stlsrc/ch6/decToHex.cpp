/*************************************************************************
	> File Name: decToHex.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 02 Sep 2016 09:29:08 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


string decToHex(int num)
{
    string strHex;
    int value = 0;
    while(num){

        value = num % 16;
        if(value < 10)
            //strHex.push_back(value + '0');
            strHex.insert(strHex.begin(), value + '0');
        else{
            //strHex.push_back(value-10 + 'a');
            strHex.insert(strHex.begin(), value-10 + 'a');

        }
        num /= 16;
    }
    return strHex;

}

int main()
{
    int num;
    cin >> num;

    cout << decToHex(num) << endl;

    return 0;
}
