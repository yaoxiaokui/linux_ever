/*************************************************************************
	> File Name: more_function.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月03日 星期日 11时06分55秒
 ************************************************************************/

/*  模拟多态问题 */


#include <iostream>
using namespace std;


class HeroFighter{
    public:
        virtual int power(){//战斗力
            return 10;
        }
};

class AdvFighter:public HeroFighter{
    public:
        int power(){
            return 20;
        }
};

class EnemyFighter{
    public:
        int attack(){//破坏力
            return 15;
        }
};


int main0()
{
    HeroFighter hf;
    EnemyFighter ef;

    AdvFighter af;

    if(hf.power() < ef.attack())
        cout << "HeroFighter failed." << endl;
    else
        cout << "HeroFighter win." << endl;

    
    if(af.power() < ef.attack())
        cout << "AdvFighter failed." << endl;
    else
        cout << "AdvFighter win." << endl;


    return 0;
}

void ObjPlay(HeroFighter * phf, EnemyFighter *pef)
{
    if(phf->power() < pef->attack())
        cout << "HeroFighter failed." << endl;
    else
        cout << "HeroFighter win." << endl;
}
int main()
{
    HeroFighter hf;
    EnemyFighter ef;

    AdvFighter af;

    ObjPlay(&hf, &ef);
    ObjPlay(&af, &ef);

    return 0;
}

