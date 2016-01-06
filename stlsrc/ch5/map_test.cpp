/*************************************************************************
	> File Name: map_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月24日 星期四 17时46分40秒
 ************************************************************************/

#include<iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;


int main()
{
    map<string, int> simap;

    simap[string("linux")] = 1;
    simap[string("ever")] = 2;
    simap[string("mapmap")] = 3;
    simap[string("setset")] = 4;

    pair<string, int> value(string("map_test"), 5);
    simap.insert(value);

    cout << "map: " << endl;
    map<string, int>::iterator it;
    for (it = simap.begin(); it != simap.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;

    int num = simap[string("map_test")];
    cout << "map_test is " << num << endl;

    it = simap.find(string("linx"));
    if(it == simap.end()){
        cout << "linx not find..\n";
    }
    else{
        cout << "linx find...\n";
    }

    it = simap.find(string("ever"));
    if(it == simap.end()){
        cout << "ever not find..\n";
    }
    else{
        cout << "ever find...\n";
    }
    
    it->second = 9999;
    num = simap[string("ever")];
    cout << "ever is " << num << endl;


    return 0;
}
