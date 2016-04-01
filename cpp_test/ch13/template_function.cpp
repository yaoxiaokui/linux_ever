/*************************************************************************
	> File Name: template_function.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月01日 星期五 09时11分57秒
    > Function: template function
 ************************************************************************/

#include <iostream>
using namespace std;


template<typename T>
T mymax(T x1, T x2)
{
    return (x1 > x2) ? x1:x2;
}

int main()
{

    char a = 'x';
    char b = 'z';
    cout << "a = " << a << ", b = " << b << endl;
    cout << "max(a, b) = " << mymax(a, b) << endl;

    int n1 = 10;
    int n2 = 9;
    cout << "n1 = " << n1 << ", n2 = " << n2 << endl;
    cout << "max(n1, n2) = " << mymax(n1, n2) << endl;

    float n3 = 10.3;
    float n4 = 11.98;
    cout << "n3 = " << n3 << ", n4 = " << n4 << endl;
    cout << "max(n3, n4) = " << mymax(n3, n4) << endl;


    return 0;
}
