/*************************************************************************
	> File Name: coinChange.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 15 Aug 2016 02:59:12 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int counts(vector<int> & v, int index, int sum)
{
    //还有钱，但是已经没有硬币了
    if(index < 0 && sum > 0)
        return 0;

    //已经刚好没有硬币了
    if(sum == 0)
        return 1;
    else if(sum < 0)
        return 0;
    
    return counts(v, index, sum-v[index]) + counts(v, index-1, sum);
}

int counts2(vector<int> & v, int index, int sum)
{
    int count[index+1][sum+1];

    //初始化为0
    for(int i = 0; i <= index; ++i){
        for(int j = 0; j <= sum; ++j)
            count[i][j] = 0;
    }
    

    for(int i = 0; i <= index; ++i){
        for(int j = 0; j <= sum; ++j){
            if(count[i]) 
        }
        
    }
    
}


int main()
{

    int N = 0;

    cout << "Input the sum: ";
    cin >> N;

    vector<int> v;
    int value;

    cout << "Input v: ";
    while(cin >> value){
        v.push_back(value);
    }


    int count = counts(v, v.size()-1, N);
    cout << "count = " << count << endl;

    count = counts2(v, v.size()-1, N);
    //cout << "count = " << count << endl;
    


    return 0;
}
