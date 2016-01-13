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

    cout << "5：";
    for (int i = 0; i < v.size()-5; i++){
        if(v[i] > v[i+5]){
            int tmp = v[i];
            v[i] = v[i+5];
            v[i+5] = tmp;
        }
    }
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "3：";
    for (int i = 0; i < v.size()-3; i++){
        if(v[i] > v[i+3]){
            int tmp = v[i];
            v[i] = v[i+3];
            v[i+3] = tmp;
        }
    }
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "2：";
    for (int i = 0; i < v.size()-2; i++){
        if(v[i] > v[i+2]){
            int tmp = v[i];
            v[i] = v[i+2];
            v[i+2] = tmp;
        }
    }
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "1：";
    for (int i = 0; i < v.size()-1; i++){
        if(v[i] > v[i+1]){
            int tmp = v[i];
            v[i] = v[i+1];
            v[i+1] = tmp;
        }
    }
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
