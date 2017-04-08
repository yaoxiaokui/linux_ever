/*************************************************************************
	> File Name: findCoder.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 25 Aug 2016 09:51:31 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>
using namespace std;

void print(vector<string> & v)
{
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << endl;
    }
}

int getCoderCount(string & str)
{
    int count = 0;
    int index = 0;
    string temp;
    for(int i = 0; i < str.size(); ++i){
        temp.push_back(tolower(str[i])); 
    }
    //cout << "temp = " << temp << endl;

    while((index = temp.find("coder", index)) != string::npos){
        count++;
        index += 5;
    }

    return count;
}

struct great
{
    bool operator()(const int x, const int y){
        return x>y;
    }
};


int main()
{
    int n;
    cin >> n;
    cin.get();

    vector<string> v;

    for(int i = 0; i < n; ++i){
        string temp;
        getline(cin, temp);
        v.push_back(temp);
    }

    print(v);

    map<string, int> coderMap;
    for(int i = 0; i < n; ++i){
        cout << i << ", count = " << getCoderCount(v[i]) << endl;
        coderMap[v[i]] = getCoderCount(v[i]);
        //cout << getCoderCount(v[i]) << endl;
    }

    multimap<int, string, great> resultMap;
    for(map<string, int>::iterator it = coderMap.begin(); it != coderMap.end(); ++it){
        if(it->second > 0)
            //resultMap[it->second] = it->first; 
            resultMap.insert(pair<int, string>(it->second, it->first));
    }

    vector<string> resultV;
    for(multimap<int, string, great>::iterator it = resultMap.begin(); it != resultMap.end(); ++it){
        resultV.push_back(it->second);
    }

    cout << "result:------------------- " << endl;
    print(resultV);

    return 0;
}
