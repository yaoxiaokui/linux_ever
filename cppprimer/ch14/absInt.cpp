/*************************************************************************
	> File Name: absInt.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Apr 2017 10:17:32 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class absInt{

public:
    int operator()(int val) const{
        return val < 0 ? -val : val;
    }

};


int main()
{
    int i = -42;
    absInt absObj;

    cout << "absObj(-42) = " << absObj(i) << endl;

    int j = 23;
    cout << "absObj(23) = " << absObj(j) << endl;


    return 0;
}
