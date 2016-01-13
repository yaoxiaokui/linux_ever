/*************************************************************************
	> File Name: for_each.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 11时48分39秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;


template<class T>
struct print{
    
    print(ostream & output):os(output), count(0){}
    void operator()(T x){
        os << x << " ";
        count++;
    }
    ostream & os;
    int count;
};

int main()
{
    int A[] = {1, 4, 2, 8, 5, 7};
    const int N = sizeof(A)/sizeof(int);


    print<int> p = for_each(A, A+N, print<int>(cout));
    cout << endl;

    cout << p.count << endl;

    char * commands[] = {"uptime", "pwd", "ls"};
    int num = 3;
    for_each(commands, commands+num, system);

    return 0;
}
