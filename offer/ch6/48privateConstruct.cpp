/*************************************************************************
	> File Name: 48privateConstruct.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Jul 2016 10:58:41 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class FinalClass{
private:
    FinalClass(){}
    ~FinalClass(){}
public:
    static FinalClass * newObject(){
        return new FinalClass();
    }

    static void deleteObject(FinalClass * pObject){
        delete pObject;
    }

    void print(){
        cout << "FinalClass.print()" << endl;
    }
};


int main()
{
    FinalClass * finalObject = FinalClass::newObject();
    finalObject->print();
    FinalClass::deleteObject(finalObject);

    return 0;
}
