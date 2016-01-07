/*************************************************************************
	> File Name: insert_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月06日 星期三 22时31分28秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <functional>
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

template<class Iterator, class Obj, class Comparator>
void insert_sort_help(const Iterator & begin, const Iterator & end, const Obj & obj, const Comparator &comp)
{
    Iterator j;
    for (Iterator i = begin+1; i != end; ++i){
        Obj tmp = *i;
        //for (j = i; j != begin && tmp < *(j-1); j--){
        for (j = i; j != begin && comp(tmp, *(j-1)); j--){
            *j = *(j-1);
        }
        *j = tmp;
    }
}

template<class Iterator, class Comparator>
void insert_sort(const Iterator & begin, const Iterator & end, const Comparator & comp)
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
    insert_sort_help(begin, end, *begin, comp);
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

#if 1
    vector<int> data;
    input_data(data);

    cout << "从小到大排序，";
    insert_sort(data.begin(), data.end(), less<int> ());//从小到大排序
    output_data(data.begin(), data.end());
    
    cout << "从大到小排序，"; 
    insert_sort(data.begin(), data.end(), greater<int> ());//从大到小排序
    output_data(data.begin(), data.end());

#else
    vector<string> str_data;
    input_data(str_data);

    cout << "从小到大排序，";
    insert_sort(str_data.begin(), str_data.end(), less<string> ());//从小到大排序
    output_data(str_data.begin(), str_data.end());

    cout << "从大到小排序，"; 
    insert_sort(str_data.begin(), str_data.end(), greater<string> ());//从大到小排序
    output_data(str_data.begin(), str_data.end());
#endif

    return 0;
}
