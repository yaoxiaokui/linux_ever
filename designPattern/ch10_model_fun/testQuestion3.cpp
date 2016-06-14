/*************************************************************************
	> File Name: testQuestion.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 14 Jun 2016 07:55:18 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//老师的试卷类(基类)
class Paper
{
public:
    void question1(){
        cout << "问题1: 2*2 = ()" << endl;
        cout << "选项: A: 2, B: 3, C: 4, D: 5" << endl;
        cout << "答案: " << answer1() << endl << endl;
    }

    void question2(){
        cout << "问题2: 3/2 = ()" << endl;
        cout << "选项: A: 2, B: 3, C: 4, D: 1" << endl;
        cout << "答案: " << answer2() << endl << endl;
    }

    void question3(){
        cout << "问题3: 2-2 = ()" << endl;
        cout << "选项: A: 0, B: 3, C: 4, D: 5" << endl;
        cout << "答案: " << answer3() << endl << endl;
    }

    //下面是三个问题的答案
    virtual string answer1(){
        return "";
    }

    virtual string answer2(){
        return "";
    }

    virtual string answer3(){
        return "";
    }
};

//学生A抄写的试卷
class PaperA : public Paper
{
public:
    //下面是三个问题的答案
    virtual string answer1(){
        return "C";
    }

    virtual string answer2(){
        return "D";
    }

    virtual string answer3(){
        return "A";
    }
};


//学生B抄写的试卷
class PaperB : public Paper
{
public:
    //下面是三个问题的答案
    virtual string answer1(){
        return "A";
    }

    virtual string answer2(){
        return "A";
    }

    virtual string answer3(){
        return "A";
    }

};

int main()
{
    //创建学生A抄写的试卷对象
    PaperA studentA;
    cout << "studentA的试卷: " << endl;
    studentA.question1();
    studentA.question2();
    studentA.question3();
    
    //创建学生B抄写的试卷对象
    PaperB studentB;
    cout << "studentB的试卷: " << endl;
    studentB.question1();
    studentB.question2();
    studentB.question3();


    return 0;
}
