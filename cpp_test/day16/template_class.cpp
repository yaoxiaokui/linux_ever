/*************************************************************************
	> File Name: template_class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月02日 星期六 17时17分07秒
 ************************************************************************/

#include <iostream>
using namespace std;



template<typename T>
class Complex
{
    private:
        T real, image;

    public:
        Complex(T r = 0, T i = 0):real(r), image(i){}
        Complex(){}
        ~Complex(){}
    
        void print() const;
        
        friend Complex<T> operator+(const Complex<T> & c1, const Complex<T> & c2)
        {
            Complex<T> temp(c1.real+c2.real, c1.image+c2.image);
            return  temp;
        }
        friend Complex operator-(const Complex & c1, const Complex & c2)
        {
            Complex<T> temp(c1.real-c2.real, c1.image-c2.image);
            return  temp;
        }
};

template<typename T>
void Complex<T>::print() const
{
    cout << "real = " << real << ", image = " << image << endl;
}

/*不能放在外面定义，编译会出错
template<typename T>
Complex<T> Complex<T>::operator+(const Complex<T> & c1, const Complex<T> & c2)
{
    Complex<T> temp(c1.real+c2.real, c1.image+c2.image);
    return temp;
}
*/

int main()
{
    Complex<int> c1(1, 1);
    c1.print();

    Complex<int> c2(2, 2);
    c2.print();

    Complex<int> c3 = c1 + c2;
    c3.print();

    Complex<int> c4 = c1 - c2;
    c4.print();

    return 0;
}
