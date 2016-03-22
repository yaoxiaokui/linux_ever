/*************************************************************************
	> File Name: 163_test1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月22日 星期二 13时55分52秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int fun(int v1, int v2)
{
    int max = 0;

    for(int i = 1; i <= v1; ++i){
        if((v1%i == 0) && (v2%i == 0) && (max < i))
            max = i;
    }

    return max;
}

int fun1(int v1, int v2)
{
    int remainder;

    do{
        remainder = v1 % v2;
        v1 = v2;
        v2 = remainder;

    }while(remainder);

    return v1;
}

int main()
{
    int n, a;
    int val;
    vector<int> b;

    while(cin >> n >> a){

        for(int i = 0; i < n; ++i){
            cin >> val;
            b.push_back(val);
        }

        for(int i = 0; i < n; ++i){
            if(b[i] <= a)
                a += b[i];
            else 
                a += fun(a, b[i]);
        }

        cout << a << endl;
        b.clear();
    }




    return 0;
}
