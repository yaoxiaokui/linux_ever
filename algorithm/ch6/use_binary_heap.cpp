/*************************************************************************
	> File Name: use_binary_heap.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月09日 星期六 15时43分24秒
 ************************************************************************/

#include <iostream>
#include "BinaryHeap.h"
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(14);
    v.push_back(16);
    v.push_back(19);
    v.push_back(21);
    v.push_back(19);
    v.push_back(68);
    v.push_back(13);
    v.push_back(65);
    v.push_back(26);
    v.push_back(32);
    v.push_back(31);

    BinaryHeap<int> binHeap(v); 
    binHeap.output();

    vector<int> v2;
    v2.push_back(150);
    v2.push_back(80);
    v2.push_back(40);
    v2.push_back(30);
    v2.push_back(10);
    v2.push_back(70);
    v2.push_back(110);
    v2.push_back(100);
    v2.push_back(20);
    v2.push_back(90);
    v2.push_back(60);
    v2.push_back(50);
    v2.push_back(120);
    v2.push_back(140);
    v2.push_back(130);
    
    BinaryHeap<int> bindHeap2(v2);
    bindHeap2.output();
    cout << "获得最小元素并删除最小元素：";
    int minVal;
    bindHeap2.deleteMin(minVal);
    cout << minVal << endl;
    bindHeap2.output();

    return 0;
}

