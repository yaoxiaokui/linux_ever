/*************************************************************************
	> File Name: builder.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 17 Jun 2016 07:29:08 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


//父类
class Person
{
public:

    void buildHead(){
        cout << "头" << endl;
    }

    virtual void buildBody(){}

    void buildLeftArm(){
        cout << "左胳膊 ";
    }

    void buildRightArm(){
        cout << "右胳膊" << endl;
    }

    void buildLeftLeg(){
        cout << "左腿 ";
    }
    
    void buildRightLeg(){
        cout << "右腿" << endl;
    }

    void build(){
        buildHead();
        buildBody();
        buildLeftArm();
        buildRightArm();
        buildLeftLeg();
        buildRightLeg();
    }

};

//创建一个胖人类
class FatPerson : public Person
{
public:

    void buildBody(){
        cout << "胖身体" << endl;
    }
};

//创建一个瘦人类
class ThinPerson : public Person
{
public:

    void buildBody(){
        cout << "瘦身体" << endl;
    }
};

//客户端
int main()
{
    //创建一个胖人对象
    FatPerson fatPerson;
    fatPerson.build();

    cout << "---------------------------------" << endl;

    //创建瘦人对象
    ThinPerson thinPerson;
    thinPerson.build();
    

    return 0;
}
