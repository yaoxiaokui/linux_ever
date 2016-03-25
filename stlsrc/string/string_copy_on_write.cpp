/*************************************************************************
	> File Name: string_copy_on_write.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月25日 星期五 20时22分39秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main()
{
    string str1 = "linux_ever";
    string str2 = str1;

    cout << "查看str1和str2中内容指向的地址: " << endl;

    printf("str1's address is %x\n", str1.c_str());
    printf("str2's address is %x\n", str2.c_str());

    cout << "\n输出两个string对象的值之后的内存地址：" << endl;
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;
    printf("str1's address is %x\n", str1.c_str());
    printf("str2's address is %x\n", str2.c_str());

    cout << "\n修改了str2之后的地址：" << endl;
    str2[1] = 'u';
    printf("str1's address is %x\n", str1.c_str());
    printf("str2's address is %x\n", str2.c_str());

    cout << "\n修改了str1之后的地址：" << endl;

    str1[1] = 'w';
    printf("str1's address is %x\n", str1.c_str());
    printf("str2's address is %x\n", str2.c_str());

    return 0;
}

