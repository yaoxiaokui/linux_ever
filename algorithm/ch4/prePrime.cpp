/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月13日 星期三 13时38分18秒
 ************************************************************************/

#include <iostream>
using namespace std;


int prePrime(int n)
{
    int i;

    if(n % 2 == 0)
        n--;

    for(; ; n -= 2){
        for(i = 3; i*i <= n; i+= 2){
            if(n % i == 0)
                goto ContOuter;
        }
        return n;

        ContOuter: ;
    }
}


int main()
{
    int x;

    cin >> x;

    int n = prePrime(x);
    cout << "n = " << n << endl;


    return 0;
}
