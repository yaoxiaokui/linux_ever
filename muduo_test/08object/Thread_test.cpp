/*************************************************************************
	> File Name: Thread_test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Jan 2017 10:32:19 AM CST
 ************************************************************************/

#include <iostream>
#include "Thread.h"
#include <unistd.h>
using namespace std;

class TestThread : public Thread
{
public:
    TestThread(int count):count_(count){
        cout << "TestThread()..." << endl;
    }

    ~TestThread(){
        cout << "~TestThread()..." << endl;
    }

    void Run(){
        while(count_--){
            cout << "this is a test ...." << endl;
            sleep(1);
        }
    }

    int count_;
};


int main()
{
    /*
    TestThread t(5);
    t.Start();
    t.Join();
    */

    TestThread * thread = new TestThread(5);
    thread->SetAutoDelete(true);
    thread->Start();
    thread->Join();
    
    return 0;
}
