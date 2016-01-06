/*************************************************************************
	> File Name: more_work_2_2_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月25日 星期三 22时14分25秒
 ************************************************************************/

#include<iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

void input_data(int num, vector<int> &rhs1, vector<int> &rhs2, vector<Pair> & dat)
{
    int i = 0;
    int time;
    cout << "num: ";
    cin >> num;
    cout << "start: ";
    
    for (i = 0; i < num; ++i){
        cin >> num;
        rhs1.push_back(num);
        cin.get();
        cin.get();
    }
    cout << "end: ";
    for (i = 0; i < num; ++i){
        cin >> num;
        rhs2.push_back(num);
        cin.get();
        cin.get();
    }
    Pair foo;
    
    foo = make_pair(2, 6);
    cout << "make pair:\n";
    for (i = 0; i < num; ++i){
        //dat.push_back(make_pair(rhs1[i], rhs2[i]));
        cout << "i = " << i << endl;
        dat.push_back(foo);
    }

    //sort the data
    //sort(data.begin(), data.end());
}

void output_data(vector<Pair> &crhs)
{
    cout << "output the data:\n";
    vector<Pair>::iterator pos;
    if(crhs.empty()){
        cout << "data is empty" << endl;
    }
    else{
        cout << "data is not empty" << endl;
    }
    for (pos = crhs.begin(); pos != crhs.end(); ++pos){
        cout << "first: " << pos->first << ", second: " << pos->second << endl;
    }
}
int main()
{
    int num;
    vector<int> start;
    vector<int> end;
    vector<Pair> data;
    input_data(num, start, end, data);

    output_data(data);

    exit(0);
}
