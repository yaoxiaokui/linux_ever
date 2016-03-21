/*************************************************************************
	> File Name: random.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月21日 星期一 13时21分16秒
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main(int argc, char*argv[])
{
    srand((unsigned)time(NULL));
    int max = atoi(argv[1]);
    cout << "max = " << max << endl;

    int val = rand()%max;

    cout << "val = " << val << endl;

    return 0;
}
