/*************************************************************************
	> File Name: 51.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月13日 星期五 10时06分39秒
 ************************************************************************/

#include<iostream>
#include "Myrational.h"
#include <stdlib.h>
using namespace std;

int main(int argc, char **argv)
{
    if (argc == 5){
        try{
            MyRational x(atol(argv[1]), atol(argv[2]));
            MyRational y(atol(argv[3]), atol(argv[4]));
            cout << x + y << endl;
        }
        catch(gerenal_expection &X){
            cout << X.message() << endl;
        }
    }

    exit(0);
}
