/*************************************************************************
	> File Name: sizeof.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月01日 星期五 11时04分36秒
 ************************************************************************/

#include <iostream>
using namespace std;
#pragma pack(4)
//大小为16个字节，参考第一个规则
struct s1{
    char a;
    short b;
    double c;
};

//大小为24个字节，参考第二个规则
struct s2{
    char d;
    struct s1 s11;
};

//大小为24个字节,参考第三个规则
struct s3{
    char a;
    double b;
    short c;
};


int main()
{
    cout << "sizeof(s1) = " << sizeof(struct s1) << endl;
    cout << "sizeof(s2) = " << sizeof(struct s2) << endl;
    cout << "sizeof(s3) = " << sizeof(struct s3) << endl;

    return 0;
}

