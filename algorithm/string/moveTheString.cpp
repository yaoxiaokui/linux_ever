/*************************************************************************
	> File Name: moveTheString.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Aug 2016 09:47:00 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void fun(string & str)
{
    int length = str.size();
    for(int i = 0; i < length; ++i){
        if(str[i] >= 'a' && str[i] <= 'z'){
            //向前移动直到移动到一个大写字符处
            for(int j = i-1; j >= 0; --j){
                if(str[j] >= 'A' && str[j] <= 'Z'){
                    swap(str[i], str[j]);
                    i = 0;
                    break;
                }
            }
        }
    }

}

int main()
{
    string str;

    while(getline(cin, str)){
        fun(str);
        cout << str << endl;
    }


    return 0;
}
