/*************************************************************************
	> File Name: maptest1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 25 Mar 2017 10:39:36 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <string>
using namespace std;


int main()
{
    map<string, int> wordcount;
    string word;

    while(cin >> word){
        wordcount[word]++;
    }

    for(auto & it : wordcount){
        cout << it.first << ": " << it.second << endl;
    }
    

    return 0;
}
