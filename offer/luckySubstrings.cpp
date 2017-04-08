/*************************************************************************
	> File Name: luckySubstrings.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 25 Aug 2016 09:04:25 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


void print(vector<string> & v)
{
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << endl;
    }
}


int getDiffCount(string & str)
{
    string temp = str;
    string::iterator it = unique(temp.begin(), temp.end());
    //cout << "unique temp: " << temp << ", str = " << str << endl;

    return distance(temp.begin(), it);
    //return temp.size();
}

//获得所有的子串
vector<string> getSubstrings(string & str)
{
    vector<string> v;
    int len = str.size();

    for(int i = 0; i < len; ++i){
        string temp = "";
        for(int j = i; j < len; ++j){
            temp.push_back(str[j]);
            v.push_back(temp);
        }
    }

    vector<string>::iterator it = unique(v.begin(), v.end());
    cout << "distance(v.begin(), it) = " << distance(v.begin(), it) << endl;
    cout << "v.size() = " << v.size() << endl;

    v.resize(distance(v.begin(), it));


    return v;
}

void initMap(map<int, int> & m)
{
    int num1 = 0;
    int num2 = 1;
    int num = 0;

    for(int i = 2; i < 12; ++i){
        num = num1 + num2;
        m[num]++;
        num1 = num2;
        num2 = num;
    }
}

void printSubstrings(vector<string> & v, map<int, int> & m)
{
    int count = 0;
    for(int i = 0; i < v.size(); ++i){
        count = getDiffCount(v[i]);
        if(m[count])
            cout << v[i] << endl;
    }
}
int main()
{
    string str;

    //cout << "input the str: ";
    while(cin >> str){
        vector<string> substrings = getSubstrings(str);
        print(substrings);

        map<int, int> fibonacciMap;
        initMap(fibonacciMap);

        //printSubstrings(substrings, fibonacciMap);
    }

    return 0;
}
