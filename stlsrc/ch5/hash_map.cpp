/*************************************************************************
	> File Name: hash_set.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 11 Jun 2016 03:59:19 PM CST
 ************************************************************************/

#include <iostream>
#include <hash_map>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;
using namespace __gnu_cxx;


int main()
{
    hash_map<int, string> iMap;

    iMap[2] = "map";
    iMap[4] = "linux";
    iMap[3] = "ever";
    iMap[8] = "set";
    iMap[7] = "tryHard";

    cout << "iMap: " << endl;

    hash_map<int, string>::iterator it;
    for(it = iMap.begin(); it != iMap.end(); ++it){
        cout << it->first << ": " << it->second << endl;
    }



    hash_map<const char*, int> days;

    days["jarr"] = 31;
    days["ever"] = 23;
    days["linux"] = 23;


    cout << "--------------------------------------" << endl;
    cout << "days: " << endl;

    hash_map<const char*, int>::iterator itr;
    for(itr = days.begin(); itr != days.end(); ++itr){
        cout << itr->first << ": " << itr->second << endl;
        
    }


    return 0;
}

