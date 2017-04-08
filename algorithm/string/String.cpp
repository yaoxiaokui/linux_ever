/*************************************************************************
	> File Name: String.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Aug 2016 04:40:08 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;


class String{

private:
    char * str;
public:
    //String():str(NULL){}
    //普通构造函数
    String(const char * pStr = NULL);
    //复制构造函数
    String(const String & string);
    //重载赋值运算符
    String & operator=(const String & other);

    ~String();
public:
    friend ostream & operator<<(ostream & os, const String & string);
};

ostream & operator<<(ostream & os, const String & string)
{
    os << string.str;
    return os;
}

String::~String()
{
    if(str)
        delete str;
}

String::String(const char * pStr)
{
    if(pStr == NULL){
        str = NULL;
        return;
    }

    int len = strlen(pStr);
    str = new char[len+1];

    strcpy(str, pStr);
}

String::String(const String & string)
{
    int len = strlen(string.str);
    str = new char[len+1];

    strcpy(str, string.str);
}


String & String::operator=(const String & other)
{
    if(this == &other)
        return *this;

    if(str)
        delete str;

    int len = strlen(other.str);

    str = new char[len+1];
    strcpy(str, other.str);

    return *this;
}


int main()
{
    String str1("hello");
    cout << str1 << endl;

    String str2;
    str2 = str1;

    String str3 = str1;
    cout << str2 << endl;
    cout << str3 << endl;
    

    return 0;
}
