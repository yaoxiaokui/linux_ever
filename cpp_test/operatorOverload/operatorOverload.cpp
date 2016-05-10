/*************************************************************************
	> File Name: operatorOverload.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年05月10日 星期二 15时27分01秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Mail;

//发件人类
class Sender
{
public:
    Sender(string addr):_addr(addr){}
    Sender & operator<<(Mail & mail);

private:
    string _addr;
};


//Mail类
class Mail
{
public:
    Mail(){}
    Mail(string title, string contents, string time)
        :_title(title), _contents(contents), _time(time){}

    friend Sender & Sender::operator<<(Mail & mail);
private:
    string _title;
    string _contents;
    string _time;
};

//必须放在Mail声明的后面
Sender & Sender::operator<<(Mail & mail)
{
    cout << _addr << ": ";
    cout << mail._title << " " << mail._contents << " " << mail._time << endl;
    return *this;
}


int main()
{
    Sender sender("linux_ever@163.com");
    Mail mail1("开会", "做报告", "2016-5-10");
    Mail mail2("散会", "发错了", "2016-5-12");

    sender << mail1;
    sender << mail2;


    return 0;
}
