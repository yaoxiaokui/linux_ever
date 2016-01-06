/*************************************************************************
	> File Name: binary_search.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月11日 星期三 14时24分09秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void output_vector(const vector<int> &v)
{
    cout << "The vector is :";
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
/*recursion递归查找*/
int binary_search_recursion(const vector<int> &v, int low, int high, int goal)
{
    if (low <= high){
        int middle = (low + high) / 2;
        if (goal == v[middle])
            return middle;
        else if (goal > v[middle])
            binary_search_recursion(v, middle+1, high, goal);
        else
            binary_search_recursion(v, low, middle-1, goal);
    }
    else    
        return -1;
}

/*不是递归*/
int  binary_search(const vector<int> &v, int high, int goal)
{
    int low = 0, middle = 0;

    while(low <= high){
        middle = (low + high) / 2;
        if(goal == v[middle])
            return middle;
        else if(goal > v[middle])
            low = middle+1;
        else
            high = middle-1;
    }
    
    return -1;
}

int main()
{
    int num;
    cout << "input the num of the data:";
    cin >> num;
    vector<int> v;
    cout << "Input the data to the vector:" << endl;
    int val;
    while(num != 0){
        cin >> val;
        v.push_back(val);
        num--;
    }

    output_vector(v);
    sort(v.begin(), v.end());
    cout << "After sort ";
    output_vector(v);

    cout << "input the goal value to find: ";
    int goal;
    cin >> goal;
    /*递归*/
    int index =  binary_search_recursion(v, 0, v.size()-1, goal);
    if (index != -1)
        cout << "goal is == v[" << index << "]" << endl;
    else
        cout << "goal is not at the vector" << endl;
    /*非递归*/
    index = binary_search(v, v.size(), goal);
    if (index != -1)
        cout << "goal is == v[" << index << "]" << endl;
    else
        cout << "goal is not at the vector" << endl;

    return 0;
}

