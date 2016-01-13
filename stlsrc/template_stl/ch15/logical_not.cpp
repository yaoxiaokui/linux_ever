/*************************************************************************
	> File Name: logical_and.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月13日 星期三 10时11分48秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;


int main()
{

    bool foo[] = {true, false, true, false};
    bool bar[] = {true, true, false, false};
    bool result[4];

    transform(foo, foo+4, result, logical_not<bool>());

    for(int i = 0; i < 4; ++i){
        cout << foo[i] << " not " << " = " << result[i] << endl;
    }

    return 0;
}

