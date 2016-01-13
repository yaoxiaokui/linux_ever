/*************************************************************************
	> File Name: remove.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 09时22分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <functional>
using namespace std;

int main()
{
    vector<string> v;
    v.push_back("linux");
    v.push_back("ever");
    v.push_back("linux_ever");
    v.push_back("time");
    v.push_back("Author");
    v.push_back("Time");
    v.push_back("ever");
    v.push_back("linux");


    cout << "old V: ";
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    cout << "new V: ";
    remove_copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "), string("ever"));
    cout << endl;

    cout << "old V: ";
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    return 0;
}
