/*************************************************************************
	> File Name: mylist_iter_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月19日 星期六 16时35分43秒
 ************************************************************************/

#include<iostream>
#include "mylist_iter.h"
using namespace std;


int main()
{
    List<int> mylist;

    for (int i = 0; i < 5; ++i){
        mylist.insert_front(i);
        mylist.insert_end(i+2);
    }

    mylist.display();



    return 0;
}
