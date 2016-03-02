/*************************************************************************
	> File Name: 6_3_map_pair.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月02日 星期三 11时06分43秒
 ************************************************************************/

#include <iostream>
#include <map>
#include <utility>
#include <string>
using namespace std;


int main()
{
    map<string, pair<int, double> > m;

    string name;
    double value;

    while(cin >> name >> value){
        if(m.find(name) == m.end()){//没有找到name，则要重新创建一个成员
            m[name] = make_pair(1, value);
        }
        else{
            m[name].first++;
            m[name].second += value;
        }
    }

    int num = 0;
    double sum = 0.0;

    for(map<string, pair<int, double> >::iterator it = m.begin(); it != m.end(); ++it){
        cout << (*it).first << ": sum = " << (*it).second.second << ", avg = " << it->second.second / it->second.first << endl;
        num += it->second.first;
        sum += it->second.second;
    }
    
    cout << "all sum = " << sum << ", avg = " << sum / num << endl;

    return 0;
}
