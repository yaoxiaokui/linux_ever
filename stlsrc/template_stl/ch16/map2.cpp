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
#include <string>
#include <functional>
#include <utility>
#include <cstring>
using namespace std;


struct less_str{

    bool operator()(const char * s1, const char * s2) const{
        return strcmp(s1, s2) < 0;
    }
};

int main()
{
    map<string, int> M;
    M.insert(make_pair("A", 17));
    M.insert(make_pair("B", 18));

    if(M.find("Z") == M.end()){
        cout << "not find Z" << endl;
    }




    map<const char *, int, less_str>::iterator it;
    for (it = days.begin(); it != days.end(); ++it){
        cout << (*it).first << ": " << (*it).second << endl;
    }


    return 0;
}

