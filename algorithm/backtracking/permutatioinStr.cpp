/*************************************************************************
	> File Name: permutatioinStr.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 04 Sep 2016 05:07:16 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void printPermutation(string & str)
{
    cout << "排列: " << endl;
    sort(str.begin(), str.end());
    cout << str << endl;

    while(next_permutation(str.begin(), str.end())){
        cout << str << endl;
    }
}

void printPermutation2(string & str, int low, int high)
{
    if(low == high)
        cout << str << endl;

    for(int i = low; i <= high; ++i){
        swap(str[low], str[i]);

        printPermutation2(str, low+1, high);

        swap(str[low], str[i]);
    }

}


int main()
{
    string str;

    cin >> str;

    printPermutation(str);

    cout << "排列: " << endl;
    printPermutation2(str, 0, str.size()-1);



    return 0;
}

