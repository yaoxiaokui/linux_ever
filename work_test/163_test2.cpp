/*************************************************************************
	> File Name: 163_test2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月22日 星期二 14时19分10秒
 ************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;


int reached(int r, int x1, int y1, int x2, int y2)
{
    if(r >= (sqrt(pow(x1-x2, 2) + pow(y1-y2, 2))))
       return 1;

    else
       return 0;
}

int main()
{
    int r, x1, y1, x2, y2, x3, y3, x0, y0;

    while(cin >> r >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x0 >> y0){
        int br = 0;

        if(reached(r, x1, y1, x0, y0))
            br++;
        if(reached(r, x2, y2, x0, y0))
            br++;
        if(reached(r, x3, y3, x0, y0))
            br++;

        cout << br << "x" << endl;
    }

    return 0;
}

