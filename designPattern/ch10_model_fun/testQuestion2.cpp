/*************************************************************************
	> File Name: testQuestion.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 14 Jun 2016 07:55:18 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//老师的试卷类(基类)
class Paper
{
public:
    void question1(){
        cout << "问题1: 2*2 = ()" << endl;
        cout << "选项: A: 2, B: 3, C: 4, D: 5" << endl;
    }

    void question2(){
        cout << "问题2: 3/2 = ()" << endl;
        cout << "选项: A: 2, B: 3, C: 4, D: 1" << endl;
    }

    void question3(){
        cout << "问题3: 2-2 = ()" << endl;
        cout << "选项: A: 0, B: 3, C: 4, D: 5" << endl;
    }

};

//学生A抄写的试卷
class PaperA : public Paper
{
public:
    void question1(){
        Paper::question1();
        cout << "答案: C" << endl << endl;
    }

    void question2(){
        Paper::question2();
        cout << "答案: D" << endl << endl;
    }

    void question3(){
        Paper::question3();
        cout << "答案: A" << endl << endl;
    }

};


//学生B抄写的试卷
class PaperB : public Paper
{
public:
    void question1(){
        Paper::question1();
        cout << "答案: A" << endl << endl;
    }

    void question2(){
        Paper::question1();
        cout << "答案: A" << endl << endl;
    }

    void question3(){
        Paper::question1();
        cout << "答案: A" << endl << endl;
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
