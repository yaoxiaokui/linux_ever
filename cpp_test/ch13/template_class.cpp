/*************************************************************************
	> File Name: template_class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月01日 星期五 09时20分42秒
    > Function: template class
 ************************************************************************/

#include <iostream>
using namespace std;


template<typename T1, typename T2>
class TestClass 
{
    private:
        T1 n1;
        T2 n2;
    public:
        TestClass(T1 t1, T2 t2):n1(t1), n2(t2){}
        ~TestClass(){}
        void show();

};

template<typename T1, typename T2>
void TestClass<T1, T2>::show()
{
    cout << "n1 = " << n1 << ", n2 = " << n2 << endl;
}


int main()
{
    TestClass<int, int> obj1(9, 10);
    obj1.show();

    TestClass<int, char> obj2(11, 'z');
    obj2.show();
    
    TestClass<float, char> obj3(1.1, 'b');
    obj3.show();

    return 0;
}


