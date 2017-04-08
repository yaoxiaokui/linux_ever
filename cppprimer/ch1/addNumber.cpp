/*************************************************************************
	> File Name: addNumber.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Mar 2017 01:23:08 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


int main()
{
    std::cout << "Enter two numbers: ";
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2 
              << " is " << v1 + v2 << std::endl;

    return 0;
}
