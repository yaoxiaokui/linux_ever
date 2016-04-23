/*************************************************************************
	> File Name: priority_queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月22日 星期五 09时23分39秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
using namespace std;


template<typename Priority_queue>
void print(Priority_queue & queue)
{
    while(!queue.empty())
    {
        cout << queue.top() << " ";
        queue.pop();
    }
    cout << endl;
}


int main()
{
    priority_queue<int> maxPQ;//最大堆
    priority_queue<int, vector<int>, greater<int> > minPQ;//最小堆

    minPQ.push(4);
    minPQ.push(3);
    minPQ.push(5);

    maxPQ.push(4);
    maxPQ.push(3);
    maxPQ.push(5);

    cout << "minPQ: ";
    print(minPQ);
    cout << "maxPQ: ";
    print(maxPQ);

    return 0;
}

