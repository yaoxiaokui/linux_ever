/*************************************************************************
	> File Name: two_points_distance.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月22日 星期二 13时07分51秒
 ************************************************************************/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;


int main()
{
    double x1, y1, x2, y2;
    double distance;

    while(cin >> x1 >> y1 >> x2 >> y2){
        distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
        cout << setprecision(2) << fixed << distance << endl;
    }


    return 0;
}
