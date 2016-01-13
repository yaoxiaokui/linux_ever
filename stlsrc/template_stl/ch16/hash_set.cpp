/*************************************************************************
	> File Name: hash_set.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月13日 星期三 16时01分28秒
 ************************************************************************/

#include <iostream>
#include <hash_set>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cstring>
using namespace std;

struct eqstr{
    bool operator()(const char * s1, const char * s2)const{
        return strcmp(s1, s2)==0;
    }
};

void lookup(const hash_set<const char *, hash<const char*>, eqstr> & s, const char * word)
{
    hash_set<const char *, hash<const char *>, eqstr>::iterator it = s.find(word);
    cout << word << ": " << (it == s.end()? "not present":"present") << endl;

    
}

int main()
{
    hash_set<const char *, hash<const char *>, eqstr> Set;

    Set.insert("linux");
    Set.insert("ever");
    Set.insert("map");
    Set.insert("time");
    Set.insert("author");
/*
    lookup(Set, "linux");
    lookup(Set, "ever");
    lookup(Set, "map");
    lookup(Set, "time");
    lookup(Set, "author");
*/

    return 0;
}

