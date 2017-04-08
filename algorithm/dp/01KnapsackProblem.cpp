/*************************************************************************
	> File Name: 01KnapsackProblem.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Aug 2016 09:26:57 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;


int knapsackProblem(int packageSize, vector<int> & values, vector<int> & weights, int index)
{
    if(index == 0 || packageSize == 0)
        return 0;


    if(weights[index] > packageSize)
        return knapsackProblem(packageSize, values, weights, index-1);
    else 
        return max(knapsackProblem(packageSize, values, weights, index-1),
               values[index] + knapsackProblem(packageSize-weights[index], values, weights, index-1));
}

int knapsackProblem2(int packageSize, vector<int> & values, vector<int> & weights, int index)
{
    
}

int main()
{
    
    vector<int> values;
    vector<int> weights;
    int value;
    int weight;
    int packageSize;

    cout << "input the size of package: ";
    cin >> packageSize;

    cout << "input the value and weight: ";

    while(cin >> value >> weight){
        values.push_back(value);
        weights.push_back(weight);
    }

    cout << "size = " << knapsackProblem(packageSize, values, weights, values.size()-1) << endl;;



    return 0;
}
