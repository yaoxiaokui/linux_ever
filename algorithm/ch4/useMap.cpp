/*************************************************************************
	> File Name: useMap.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月11日 星期一 22时47分15秒
 ************************************************************************/

#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;


void print(const map<string, double> & m)
{
    for(map<string, double>::const_iterator it = m.begin(); it != m.end(); ++it)
        cout << it->first << ": " << it->second << endl;
}
int main()
{
    map<string, double> salaries;

    salaries["pat"] = 1234.02;
    cout << "pat's salaries = " << salaries["pat"] << endl;
    cout << "jan's salaries = " << salaries["jan"] << endl;

    map<string, double>::iterator it = salaries.find("usa");
    if(it == salaries.end())
        cout << "not find usa" << endl;
    else
        cout << "*it = " << it->second << endl;

    it = salaries.find("pat");
    if(it == salaries.end())
        cout << "not find pat" << endl;
    else
        cout << "*it = " << it->first << " : " << it->second << endl;


    salaries["ever"] = 4321.00;

    print(salaries);


    return 0;
}

