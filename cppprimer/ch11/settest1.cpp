/*************************************************************************
	> File Name: settest1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 25 Mar 2017 10:45:44 PM CST
 ************************************************************************/

#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    set<string> words;
    string word;

    while(cin >> word){
        words.insert(word);
    }

    for(auto & it : words)
        cout << it << endl;



    return 0;
}
