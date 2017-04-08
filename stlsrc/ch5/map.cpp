/*************************************************************************
	> File Name: map.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 09 Jun 2016 09:13:55 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> simap;

    simap[string("jjhou")] = 1;
    simap[string("jerry")] = 2;
    simap[string("jason")] = 3;
    simap[string("jimmy")] = 4;

    map<string, int>::iterator it;

    cout << "simap: " << endl;
    for(it = simap.begin(); it != simap.end(); ++it){
        cout << (*it).first << ": " << (*it).second << endl;
    }


    pair<string, int> value("linux", 5);
    simap.insert(value);

    cout << endl;

    cout << "simap: " << endl;
    for(it = simap.begin(); it != simap.end(); ++it){
        cout << (*it).first << ": " << (*it).second << endl;
    }

    cout << endl;


    int num = simap[string("linux")];
    cout << "map[linux] = " << num << endl;

    it = simap.find(string("jerry"));
    if(it != simap.end()){
        cout << "jerry found" << endl;
    }

    it  = simap.find(string("ever"));
    if(it == simap.end()){
        cout << "ever not found" << endl;
    }
    return 0;
}

