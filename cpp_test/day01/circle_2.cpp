/*************************************************************************
	> File Name: circle_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月05日 星期六 17时29分08秒
 ************************************************************************/

#include <iostream>
using namespace std;

class circle{
    private:
        double r;
        double area;
    public:
        circle(){}
        circle(double val):r(val){}
        void set_r(int val){
            r = val;
        } 
        
        double get_r(){
            return r;
        }
        double get_len(){
            return 2*3.14*r;
        }
        double get_area(){ 
            area = 3.14*r*r;
            return area;
        }
};

int main()
{
    circle c1;

    cout << "输入半径：";
    double r;
    cin >> r;
    c1.set_r(r);
    cout << "圆的面积: " << c1.get_area() << endl;


    return 0;
}
