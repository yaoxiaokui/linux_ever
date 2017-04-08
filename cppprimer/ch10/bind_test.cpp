/*************************************************************************
	> File Name: sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Mar 2017 12:30:38 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
using namespace std;


void print(vector<string> & v)
{
    for(auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}


bool isShorter(const string & s1, const string & s2)
{
    return s1.size() < s2.size();
}

//排序，去重
void elimDups(vector<string> & v)
{

    sort(v.begin(), v.end());

    auto it = unique(v.begin(), v.end());

    v.erase(it, v.end());
}


bool check_size(const string & str, int size)
{
    return str.size() >= size;
}

ostream & osprint(ostream & os, const string & s, char ch)
{
    os << s << ch;
    return os;
}

int main()
{
    vector<string> v;

    string word;

    while(cin >> word){
        v.push_back(word);
    }


    print(v);

    //elimDups(v);
    


    sort(v.begin(), v.end());

    cout << "After sort: " << endl;
    print(v);


    //sort(v.begin(), v.end(), isShorter);
    sort(v.begin(), v.end(), bind(isShorter, std::placeholders::_2, std::placeholders::_1));
    //sort(v.begin(), v.end(), [](const string & s1, const string & s2){ return s1.size() < s2.size(); });
    cout << "After sort2: " << endl;
    print(v);

    //for_each(v.begin(), v.end(), [](const string & s){cout << s << " "; });
    ostream & os = cout;
    for_each(v.begin(), v.end(), [&os](const string & s){os << s << " "; });
    cout << endl;

    for_each(v.begin(), v.end(), bind(osprint, ref(os), std::placeholders::_1, ' '));
    cout << endl;

    int len = 4;
    auto checkstr = bind(check_size, std::placeholders::_1, len);
    auto it = find_if(v.begin(), v.end(), checkstr);
    cout << "*it = " << *it << endl;

#if 0

    auto it = find_if(v.begin(), v.end(), 
           [len](const string & s)
            { return s.size() >= len; });

    cout << "*it = " << *it << endl;
#endif

    return 0;
}
