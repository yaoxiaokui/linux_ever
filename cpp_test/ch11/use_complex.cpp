/*************************************************************************
	> File Name: use_complex.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月23日 星期三 11时18分25秒
 ************************************************************************/

#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
    complex c1;
    
    cout << "c1: " << c1;

    complex c2(3);
    cout << "c2: " << c2;

    complex c3;
    cout << "c3: " << c3;
    c3 += c2;
    cout << "c3+=c2: " << c3;

    c3 = c3 + 2;
    cout << "c3+2: " << c3;

    c3 = 2 + c3;
    cout << "2+c3: " << c3;

    complex c4(4, 9);
    cout << "c4: " << c4;

    c4 = c4 + c3;
    cout << "c4+c3: " << c4;

    complex c5 = c4;
    cout << "complex c5=c4: " << c5;

    complex c6;
    c6 = c5;
    cout << "c6=c5: " << c6;

    return 0;
}



