/*************************************************************************
	> File Name: unique.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 10时06分56秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;


bool less_nocse(char x, char y)
{
    return tolower(x) < tolower(y);
}

bool equal_nocase(char x, char y)
{
    return tolower(x) == tolower(y);
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int>::iterator new_end = unique(v.begin(), v.end());

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    v.erase(new_end, v.end());

    cout << "new v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    const char init[] = "The Standard Template Library";
    vector<char> vc(init, init + sizeof(init));

    cout << "vc: ";
    copy(vc.begin(), vc.end(), ostream_iterator<char>(cout, ""));
    cout << endl;

    sort(vc.begin(), vc.end(), less_nocse);

    cout << "sorted vc: ";
    copy(vc.begin(), vc.end(), ostream_iterator<char>(cout, ""));
    cout << endl;

    vector<char>::iterator end = unique(vc.begin(), vc.end(), equal_nocase);
    
    cout << "unique vc: ";
    copy(vc.begin(), end, ostream_iterator<char>(cout, ""));
    cout << endl;

    return 0;
}
