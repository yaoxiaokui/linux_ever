/*************************************************************************
	> File Name: 40onceNum.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Jul 2016 10:10:35 AM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <vector>
using namespace std;



int main()
{
    vector<int> v;
    map<int, int> m;

    int value;

    while(cin >> value){
        v.push_back(value); 
    }

    cout << "v: ";
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;

    //对次数进行统计
    for(int i = 0; i < v.size(); ++i){
        m[v[i]]++;
    }
    

    //输出次数为1的元素
    for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
        if(it->second == 1)
            cout << it->first << " ";
    }
    cout << endl;


    return 0;
}
