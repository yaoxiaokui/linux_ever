/*************************************************************************
	> File Name: builder.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 17 Jun 2016 07:29:08 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


//父类
class PersonBuilder
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

};

//创建一个胖人类
class FatPersonBuilder : public PersonBuilder
{
public:

    void buildBody(){
        cout << "胖身体" << endl;
    }
};

//创建一个瘦人类
class ThinPersonBuilder : public PersonBuilder
{
public:

    void buildBody(){
        cout << "瘦身体" << endl;
    }
};

//创建一个指挥类
class PersonDirector
{
private:
    PersonBuilder * personBuilder;
public:
    PersonDirector(PersonBuilder * builder):personBuilder(builder){}

    ~PersonDirector(){
        delete personBuilder;
    }

    void createPerson(){
        personBuilder->buildHead();
        personBuilder->buildBody();
        personBuilder->buildLeftArm();
        personBuilder->buildRightArm();
        personBuilder->buildLeftLeg();
        personBuilder->buildRightLeg();
    }

};

//客户端
int main()
{

    //创建一个胖人对象
    PersonDirector * personDirector = new PersonDirector(new FatPersonBuilder());
    personDirector->createPerson();


    cout << "---------------------------------" << endl;


    //创建瘦人对象
    PersonDirector * personDirector2 = new PersonDirector(new ThinPersonBuilder());
    personDirector2->createPerson();
    

    delete personDirector;
    delete personDirector2;

    return 0;
}
