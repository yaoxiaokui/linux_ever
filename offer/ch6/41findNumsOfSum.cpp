/*************************************************************************
	> File Name: 41findNumsOfSum.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Jul 2016 10:46:13 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void findNumsOfSum(vector<int> & v, int length, int sum, int *num1, int *num2)
{
    if(v.size() < 2)
        return;

    int firstIndex = 0;
    int lastIndex = length-1;

    *num1 = 0;
    *num2 = 0;

    while(firstIndex < lastIndex){

        if(v[firstIndex]+v[lastIndex] == sum){
            *num1 = v[firstIndex];
            *num2 = v[lastIndex];
            return;
        }
        else if(v[firstIndex]+v[lastIndex] > sum){
            --lastIndex;
        }
        else{
            ++firstIndex;
        }
    }
}

int main()
{
    vector<int> v;

    int value;
    int sum;
    cout << "sum: ";
    cin >> sum;

    while(cin >> value){
        v.push_back(value);
    }

    //输出v
    cout << "v: ";
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;

    int num1 = 0, num2 = 0;

    findNumsOfSum(v, v.size(), sum, &num1, &num2);
    cout << num1 << " " << num2 << endl;
    


    return 0;
}
