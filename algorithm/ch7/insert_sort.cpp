/*************************************************************************
	> File Name: insert_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月06日 星期三 22时31分28秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void input_data(vector<int> & data)
{
    cout << "输入的数据序列：";
    int tmp;
    while(cin >> tmp){
        data.push_back(tmp);
    }
}

void insert_sort(vector<int> & data)
{
    int j;
    for (int i = 1; i < data.size(); ++i){
        int tmp = data[i];
        for (j = i; j > 0 && tmp < data[j-1]; j--){
            data[j] = data[j-1];
        }
        data[j] = tmp;
    }
}

void output_data(vector<int> & data)
{
    cout << "排序的数据序列：";
    for (int i = 0; i < data.size(); ++i){
        cout << data[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> data;
    input_data(data);
    insert_sort(data);
    output_data(data);

    return 0;
}
