/*************************************************************************
	> File Name: heapsort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 20时34分07秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


inline int leftChild(int i)
{
    return 2*i+1;//因为该堆是从数组下标0开始存放值的，和上次建立二叉堆的时候不一样
}

template<class T>
void percDown(vector<T> & a, int i, int n)
{
    int child;
    T tmp;

    for (tmp = a[i]; leftChild(i) < n; i = child){
        child = leftChild(i);
        if(child != n-1 && a[child] < a[child + 1])
            child++;

        if(tmp < a[child])
            a[i] = a[child];
        else
            break;
    }
    a[i] = tmp;
}

template<class T>
void heapsort(vector<T> & v)
{
    for (int i = v.size()/2; i >= 0; --i){//建立二叉堆
        percDown(v, i, v.size());
    }
    
    for (int j = v.size()-1; j > 0; j--){
        swap(v[0], v[j]);//删除最大值
        percDown(v, 0, j);
    }
}


int main()
{
    vector<int> v;
    v.push_back(97);
    v.push_back(53);
    v.push_back(28);
    v.push_back(33);
    v.push_back(23);
    v.push_back(77);
    v.push_back(89);
    v.push_back(-8);
    v.push_back(10);

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    heapsort(v);
    cout << "sorted v: ";
    copy(v.begin(), v.end(), ostream_iterator<int> (cout, " "));
    cout << endl;


    return 0;
}
