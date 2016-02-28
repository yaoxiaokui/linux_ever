/*************************************************************************
	> File Name: 5_1_pointers.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月28日 星期日 10时43分09秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


int main()
{
    char ch = 'a';
    char * p = &ch;//一个到字符的指针
    int Iarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//包含10个整数的数组

    int (&rai)[10] = Iarr;//一个到包含10个整数的数组的引用

    string (*pas)[5] = 0;//一个到字符串的数组的指针 
    string * aps[5];//aps是一个指向字符串的指针的数组

    char ** pp = &p;//一个到字符的指针的指针
    const int cint = 100;//一个常量整数
    const int * pc = &cint;//一个到常量整数的指针
    int num = 111;
    int *const cp = &num;//一个到整数的常量指针

    return 0;
}
