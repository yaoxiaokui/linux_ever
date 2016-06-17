/*************************************************************************
	> File Name: builder.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 17 Jun 2016 07:29:08 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


//创建一个胖人类
class FatPerson
{
public:

    void build(){
        cout << "胖人:" << endl;
        cout << "头" << endl;
        cout << "胖身体" << endl;
        cout << "左胳膊和右胳膊" << endl;
        cout << "左腿和右腿" << endl;
    }
};

//创建一个瘦人类
class ThinPerson
{
public:

    void build(){
        cout << "瘦人: " << endl;
        cout << "头" << endl;
        cout << "瘦身体" << endl;
        cout << "左胳膊和右胳膊" << endl;
        cout << "左腿和右腿" << endl;
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
