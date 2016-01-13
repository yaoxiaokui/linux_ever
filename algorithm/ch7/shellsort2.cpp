/*************************************************************************
	> File Name: shellsort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月08日 星期五 22时16分24秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;



int main()
{
    vector<int> v;
    v.push_back(81);
    v.push_back(94);
    v.push_back(11);
    v.push_back(96);
    v.push_back(12);
    v.push_back(35);
    v.push_back(17);
    v.push_back(95);
    v.push_back(28);
    v.push_back(58);
    v.push_back(41);
    v.push_back(75);
    v.push_back(15);

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for (int gap = v.size()/2; gap > 0; gap /= 2){//增量序列
        for (int i = gap; i < v.size(); ++i){//对间隔为gap的子序列进行插入排序
            int tmp = v[i];
            int j = i;

            for ( ; j >= gap && tmp < v[j-gap]; j -= gap)
                v[j] = v[j-gap];

            v[j] = tmp;
            
        }
        cout << gap << ": ";
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
