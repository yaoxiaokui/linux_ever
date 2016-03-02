/*************************************************************************
	> File Name: for_to_while.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月02日 星期三 10时49分18秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input_line[1024];
    memset(input_line, 0, 1024);
    
    cout << "输入字符串\n";
    cin.getline(input_line, 1024);

    int quest_count = 0;
    int max_length = strlen(input_line);
    for(int i = 0; i < max_length; ++i){
        if(input_line[i] == '?'){
            quest_count++;
        }
    }

    cout << "quest_count = " << quest_count << endl;

    quest_count = 0;

    for(char* p = input_line; p < input_line+max_length; ++p){
        if(*p == '?'){
            quest_count++;
        }
    }

    cout << "quest_count = " << quest_count << endl;


    return 0;
}
