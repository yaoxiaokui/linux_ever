/*************************************************************************
	> File Name: find_first_of.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月09日 星期六 10时44分53秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

bool compare_case_insentive(char x, char y)
{
    return (tolower(x) == tolower(y));
}

struct comp_case_insentive
{
    bool operator()(char x, char y){
        return (tolower(x) == tolower(y));
    }
};

int main()
{
    char mychars [] = {'a', 'b', 'c', 'A', 'B', 'C'};

    vector<char> v1(mychars, mychars+6);
    vector<char>::iterator it;
    char des_str[] = {'A', 'B', 'C'};
    it = find_first_of(v1.begin(), v1.end(), des_str, des_str + 3);
    if (it != v1.end())
        cout << "The first match is " << *it << endl;
    else
        cout << "There is not match." << endl;


    it = find_first_of(v1.begin(), v1.end(), des_str, des_str + 3, compare_case_insentive);
    if (it != v1.end())
        cout << "The first match is " << *it << endl;
    else
        cout << "There is not match." << endl;

    char des_str2[] = {'B', 'C'};
    it = find_first_of(v1.begin(), v1.end(), des_str2, des_str2 + 2, comp_case_insentive());
    if (it != v1.end())
        cout << "The first match is " << *it << endl;
    else
        cout << "There is not match." << endl;

    return 0;
}
