/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月30日 星期三 22时14分55秒
 ************************************************************************/

#include<iostream>
#include <string>

using namespace std;

void solve(string & str)
{
    size_t pos_first = str.find_first_not_of(' ');
    if(pos_first == string::npos){
        cout << "This is empty string" << endl;
        return 0;
    }
    str.erase(0, pos_first);

}

int main()
{
    string str;
    cout << "input the string: " << endl;
    getline(cin, str); 
    solve(str);
    cout << "output the solved string: " << endl;
    cout << str << endl;

    return 0;
}
