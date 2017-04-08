/*************************************************************************
	> File Name: useMessages.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 31 Mar 2017 06:43:30 PM CST
 ************************************************************************/

#include <iostream>
#include "./Message.h"
#include "./Folder.h"
using namespace std;


int main()
{
    Folder f1("f1");
    Folder f2("f2");

    Message m1("I am Message1.");
    Message m2("I am Message2.");

    
    f1.addMsg(&m1);
    f1.addMsg(&m2);

    f1.print();


    return 0;
}

