/*************************************************************************
	> File Name: bin_search.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月06日 星期三 13时09分47秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void input_data(vector<int> & data)
{
    cout << "输入数据：";
    int tmp;
    while(cin >> tmp && tmp != -10000){
        data.push_back(tmp);
    }
}

void output_data(vector<int> & data)
{
    cout << "输入的数据: ";
    for (vector<int>::iterator it = data.begin(); it != data.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}
int bin_search(vector<int> & data, int val)
{
    int low = 0, high = data.size()-1;
    int mid;

    while(low <= high){
        mid = (low + high)/2;
        if(data[mid] < val)
            low = mid + 1;
        else if(data[mid] > val)
            high = mid - 1;
        else
            return mid;
    }
    return data.size();
}

int main()
{
    vector<int> data;
    input_data(data);
    //排序
    cin.get();
    sort(data.begin(), data.end());
    //输入要查找的数据
    output_data(data);
    int val;
    cout << "输入要查找的数据: ";
    cin >> val;
    int index = bin_search(data, val);
    if(index == data.size()){
        cout << "index = " << index << ", data doesn't have " << val << endl;
        return 0;
    }
    cout << "index = " << index << ", data[index] = " << data[index] << endl;
    return 0;
}
