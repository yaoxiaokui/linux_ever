/*************************************************************************
	> File Name: 48privateConstruct.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Jul 2016 10:58:41 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//不能被继承的基类
template<typename T>
class FinalBase{
    friend T;
private:
    FinalBase(){}
    ~FinalBase(){}
};


//该类虚拟继承上面的基类
class FinalClass : virtual public FinalBase<FinalClass>{
public:
    FinalClass(){}
    ~FinalClass(){}
    void print(){
        cout << "FinalClass.print()" << endl;
    }
};


int main()
{
    FinalClass * finalObject = new FinalClass();
    finalObject->print();
    delete finalObject;

    FinalClass finalObject2;
    finalObject2.print();


    return 0;
}
