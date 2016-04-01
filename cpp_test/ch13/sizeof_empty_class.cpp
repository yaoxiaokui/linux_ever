/*************************************************************************
	> File Name: sizeof.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月01日 星期五 11时04分36秒
 ************************************************************************/

#include <iostream>
using namespace std;

//一个空类
class Empty{


};

int main()
{
    Empty e;
    cout << "sizeof(e) = " << sizeof(e) << endl;

    return 0;
}

