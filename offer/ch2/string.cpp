/*************************************************************************
	> File Name: string.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 19 Jun 2016 11:00:55 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;


int main()
{
    char str1[] = "hello world";
    char str2[] = "hello world";

    char * str3 = "hello world";
    char * str4 = "hello world";

    if(str1 == str2)
        cout << "str1 == str2" << endl;
    else
        cout << "str1 != str2" << endl;

    
    if(str3 == str4)
        cout << "str3 == str4" << endl;
    else
        cout << "str3 != str4" << endl;




    return 0;
}
