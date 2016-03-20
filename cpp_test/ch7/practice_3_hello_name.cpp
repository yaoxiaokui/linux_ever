/*************************************************************************
	> File Name: practice_3_hello_name.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月20日 星期日 22时19分11秒
 ************************************************************************/
 //以一系列名字作为参数，并对每一个名字分别说hello

#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
    if(argc < 2){
        cout << "输入命令行参数" << endl;
        return -1;
    }

    for(int i = 1; i < argc; ++i){
        cout << "hello," << argv[i] << endl;
    }


    return 0;
}
