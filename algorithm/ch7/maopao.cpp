/*************************************************************************
	> File Name: quicksort2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月17日 星期日 15时36分03秒
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;


void maoPao(vector<int> & v)
{
    for(unsigned i = 0; i < v.size(); ++i){
        for(unsigned j = i+1; j < v.size(); ++j){
            if(v[i] > v[j])
                swap(v[i], v[j]);
        }
    }
}

//主函数
int main()
{
    srand(unsigned(time(0)));

    vector<int> v;

    for(int i = 0; i < 10; ++i)
        v.push_back(rand()%10);

    cout << "v: ";
    for(int i = 0; i < 10; ++i)
        cout << v[i] << " ";
    cout << endl;

    maoPao(v);

    cout << "After sort: ";
    for(int i = 0; i < 10; ++i)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
