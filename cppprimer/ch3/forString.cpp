/*************************************************************************
	> File Name: forString.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Mar 2017 06:53:56 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;

    while(cin >> str){
        for(char & ch : str)
            ch = toupper(ch);

        for(char ch : str)
            cout << ch << " ";
        cout << endl;

    }

    return 0;
}
