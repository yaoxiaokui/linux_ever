/*************************************************************************
	> File Name: set.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月13日 星期三 14时44分51秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <functional>
#include <cstring>
using namespace std;


struct less_str{

    bool operator()(const char * s1, const char * s2) const{
        return strcmp(s1, s2) < 0;
    }
};

int main()
{
    map<const char *, int, less_str> days;

    days["mon"] = 1;
    days["er"] = 2;
    days["wen"] = 3;
    days["tur"] = 4;
    days["fri"] = 5;
    days["liu"] = 6;
    days["qi"] = 7;

    cout << "liu: " << days["liu"] << endl;
    
    cout << "days: " << endl;
    map<const char *, int, less_str>::iterator it;
    for (it = days.begin(); it != days.end(); ++it){
        cout << (*it).first << ": " << (*it).second << endl;
    }


    return 0;
}

