/*************************************************************************
	> File Name: myStrlen.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Aug 2016 02:17:31 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int myStrLen(char * buff, int N)
{
    int count = 0;

    while(*(buff+count) != '\0'){
        count++;
        if(count > N)
            return N;
    }

    return count;
}

int main()
{

    char buff[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0', 'x', 'y', 'z'};
    int N;
    cout << "Input the N: ";
    cin >> N;

    cout << "buff: " << buff << endl;

    cout << "buff len = " << myStrLen(buff, N) << endl;


    return 0;
}
