/*************************************************************************
	> File Name: printString.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Apr 2017 10:48:08 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class PrintString{
public:
    PrintString(ostream & o = cout, char ch = ' '):os(o), step(ch){}

    #if 0
    void operator()(const string & s) const{
        cout << s << step;
    }
    #endif

    void operator()(const char s) const{
        cout << s << step;
    }

private:
    ostream & os;
    char step;
};


int main()
{
    PrintString printer;
    //printer("linux");
    string str = "linux";
    for_each(str.begin(), str.end(), PrintString(cout, ' '));
    cout << endl;

    PrintString printer2(cerr, '-');
    //printer2("error");
    for_each(str.begin(), str.end(), printer2);
    cout << endl;

    return 0;
}
