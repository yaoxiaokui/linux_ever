/*************************************************************************
	> File Name: replace_if.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 16时38分33秒
 ************************************************************************/

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

struct string_length_than{

    string_length_than(int len = 0):length(len){}
    bool operator()(const string & str){
        return str.size() > length;
    }
    private:
        int length;
};

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(-3);
    v.push_back(2);
    v.push_back(-1);

    cout << "v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    replace_if(v.begin(), v.end(), bind2nd(less<int>(), 0), 0);
    cout << "new v: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    string A[7] = {"origin", "master", "linux", "ever", "linux_ever", "time", "algorithm"};

    cout << "A: ";
    copy(A, A + 7, ostream_iterator<string>(cout, " "));
    cout << endl;

    replace_if(A, A + 7, string_length_than(6), "******");

    cout << "A: ";
    copy(A, A + 7, ostream_iterator<string>(cout, " "));
    cout << endl;


    return 0;
}
