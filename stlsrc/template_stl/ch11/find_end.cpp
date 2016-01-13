/*************************************************************************
	> File Name: find_end.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月09日 星期六 22时15分17秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    char * s = "executable.exe";
    char * suffix = "exe";

    const int N = strlen(s);
    const int N_suf = strlen(suffix);

    char * location = find_end(s, s + N, suffix, suffix + N_suf);
    if(location != s + N){
        cout << "find a match for " << suffix << " within " << s << endl;
        cout << "location - s = " << (location-s) << endl;
        for(int i = 0; i < N_suf; ++i){
            cout << *(location+i);
        }
        cout << endl;
    }
    else
        cout << "find no match for " << suffix << " within " << s << endl;


    return 0;
}
