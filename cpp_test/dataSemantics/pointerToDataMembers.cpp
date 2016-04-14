/*************************************************************************
	> File Name: pointerToDataMembers.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月13日 星期三 20时18分31秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;


class Point3d{
    public:
        virtual ~Point3d();

    public:
        static Point3d origin;
        float x, y, z;
};

int main()
{
    printf("&Point3d::x = %d\n", &Point3d::x);
    printf("&Point3d::y = %d\n", &Point3d::y);
    printf("&Point3d::z = %d\n", &Point3d::z);

    cout << &Point3d::x << endl;
    cout << &Point3d::y << endl;
    cout << &Point3d::z << endl;


    return 0;
}
