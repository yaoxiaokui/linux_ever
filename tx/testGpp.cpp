/*************************************************************************
	> File Name: testGpp.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Aug 2016 08:36:24 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define VALUE1 100
#define VALUE2 200

int max(int x, int y)
{
    return x>y? x:y;
}

char max(char x, char y)
{
    return x>y? x:y;
}


int main()
{
    int a = VALUE1;
    int b = VALUE2;

    cout << "max(a, b) = " << max(a, b) << endl;

    char ca = 'a';
    char cb = 'b';
    cout << "max(ca, cb) = " << max(ca, cb) << endl;


    return 0;
}

