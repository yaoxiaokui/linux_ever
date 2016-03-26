/*************************************************************************
	> File Name: string_big_num.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月25日 星期五 22时32分13秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int result[2048] = {0};

int main()
{

    string num1;
    string num2;

    cin >> num1;
    cin >> num2;

    int n = 0;
    int val;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    

    for(int i = 0; i < num1.size(); ++i){
        int add_flag = 0;
        int muliti_flag = 0;

        for(int j = 0; j < num2.size(); ++j){
            val = (num1[i]-48) * (num2[j]-48) + muliti_flag;

            muliti_flag = val / 10;
            val = val % 10;
            
            int temp = result[i+j] + val + add_flag;
            add_flag = temp / 10;

            result[i+j] = temp % 10;
        }
        result[i+num2.size()] += muliti_flag + add_flag;
    } 

//下面是将结果反转
    int first = 0;
    int last = num1.size() + num2.size() - 2;
    int num = 0;

    while(first < last){
        num = result[first];
        result[first] = result[last];
        result[last] = num;
        first++;
        last--;
    }

//输出result中的内容
    for(int i = 0; i < num1.size() +  num2.size() - 1; ++i)
        cout << result[i];
    cout << endl;

    return 0;
}

