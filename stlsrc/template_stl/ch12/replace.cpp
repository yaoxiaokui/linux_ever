/*************************************************************************
	> File Name: replace.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 16时34分04秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


int main()
{
    vector<string> fruits;
    fruits.push_back("cherry");
    fruits.push_back("apple");
    fruits.push_back("peach");
    fruits.push_back("plum");
    fruits.push_back("pear");

    cout << "fruits: ";
    copy(fruits.begin(), fruits.end(), ostream_iterator<string> (cout, " "));
    cout << endl;


    replace(fruits.begin(), fruits.end(), string("apple"), string("orange"));

    cout << "new fruits: ";
    copy(fruits.begin(), fruits.end(), ostream_iterator<string> (cout, " "));
    cout << endl;

    return 0;
}
