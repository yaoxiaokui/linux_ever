/*************************************************************************
	> File Name: insert_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月06日 星期三 22时31分28秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class Obj>
void input_data(vector<Obj> & data)
{
    cout << "输入的数据序列：";
    Obj tmp;
    while(cin >> tmp){
        data.push_back(tmp);
    }
}

template<class Iterator, class Obj>
void insert_sort_help(const Iterator & begin, const Iterator & end, const Obj & obj)
{
    Iterator j;
    for (Iterator i = begin+1; i != end; ++i){
        Obj tmp = *i;
        for (j = i; j != begin && tmp < *(j-1); j--){
            *j = *(j-1);
        }
        *j = tmp;
    }
}

template<class Iterator>
void insert_sort(const Iterator & begin, const Iterator & end)
{
    /*
    int j;
    for (int i = 1; i < data.size(); ++i){
        int tmp = data[i];
        for (j = i; j > 0 && tmp < data[j-1]; j--){
            data[j] = data[j-1];
        }
        data[j] = tmp;
    }*/
    insert_sort_help(begin, end, *begin);
}

template<class Iterator>
void output_data(const Iterator & begin, const Iterator & end)
{
    cout << "排序的数据序列：";
    for (Iterator it = begin; it != end; ++it){
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    /*
    vector<int> data;
    input_data(data);
    insert_sort(data.begin(), data.end());
    output_data(data.begin(), data.end());
    */

    vector<string> str_data;
    input_data(str_data);
    insert_sort(str_data.begin(), str_data.end());
    output_data(str_data.begin(), str_data.end());

    return 0;
}
