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


//快速排序
void quickSort(vector<int> & v, int first, int last)
{
    int value = v[first];//基准数字
    
    if(first >= last)
        return;

    int i = first;
    int j = last;

    while(i < j){

        while(v[j] >= value && i < j)
            j--;

        while(v[i] <= value && i < j)
            i++;

        swap(v[i], v[j]);
    }

    v[first] = v[i];//将中间的数字放入第一个位置，是为了将中间的数字作为基准数字
    v[i] = value;//将基准数字重新中间
    

    quickSort(v, first, i-1);
    quickSort(v, i+1, last);
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

    quickSort(v, 0, v.size()-1);

    cout << "After sort: ";
    for(int i = 0; i < 10; ++i)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
