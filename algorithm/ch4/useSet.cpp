/*************************************************************************
	> File Name: useSet.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月11日 星期一 22时15分19秒
 ************************************************************************/

#include <iostream>
#include <set>
#include <utility>
#include <cstdlib>
#include <time.h>
#include <vector>
using namespace std;


void printSet(const set<int> & s)
{
    cout << "output the values of s: ";
    for(set<int>::const_iterator it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void printVector(const vector<int> & v)
{
    cout << "output the values of v: ";
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}




int main()
{
    srand(unsigned(time(0)));

    set<int> s;

    //v中用于存储随机生成的十个数字
    vector<int> v;
    for(int i = 0; i < 10; ++i)
        v.push_back(rand() % 10);
    printVector(v);

    //将刚才随机生成的十个数字插入到set中
    for(int i = 0; i < 10; ++i)
        s.insert(v[i]);

    printSet(s);

    s.insert(s.end(), 20);//insert的两个版本
    s.insert(s.end(), 19);
    printSet(s);
    


    return 0;
}

