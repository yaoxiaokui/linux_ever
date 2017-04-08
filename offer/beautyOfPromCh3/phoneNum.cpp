/*************************************************************************
	> File Name: phoneNum.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Aug 2016 10:30:59 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <string>
using namespace std;

void stringToNum(string & word, map<char, int> & m)
{
    for(int i = 0; i < word.size(); ++i){
        cout << m[word[i]];
    }
    cout << endl;
}

void initNumOfChar(map<char, int> & m)
{
    int num = 2;

    //a-o
    for(int i = 0; i < 15; ++i){
        m['a' + i] = num + i / 3;
    }

    //p-s
    for(int i = 15; i < 19; ++i){
        m['a' + i] = 7;
    }

    //t-v
    for(int i = 19; i < 22; ++i){
        m['a' + i] = 8;
    }

    //w-z
    for(int i = 22; i < 26; ++i){
        m['a' + i] = 9;
    }
}

void printMap(map<char, int> & m)
{
    for(auto it = m.begin(); it != m.end(); ++it){
        cout << it->first << ": " << it->second << endl;
    }
}

int main()
{
    string word;
    map<char, int> m;
    initNumOfChar(m);
    printMap(m);

    cout << "input the word: ";
    cin >> word;
    stringToNum(word, m);

    return 0;
}
