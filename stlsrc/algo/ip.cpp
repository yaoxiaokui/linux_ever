#include <iostream>
#include <string>
#include <map>
using namespace std;

void init(map<char, int> & m)
{
    int value = 2;
    int i = 0;
    //a -- o
    for(char ch = 'a'; ch <= 'o'; ++ch){
        if(i == 3){
            value++;
            i = 0;
        }
            
        i++;
        m[ch] = value;    
    }
    //p-s
    for(char ch = 'p'; ch <= 's'; ++ch){
        m[ch] = 7;    
    }
     //t-v
    for(char ch = 't'; ch <= 'v'; ++ch){
        m[ch] = 8;    
    }
     //w-z
    for(char ch = 'w'; ch <= 'z'; ++ch){
        m[ch] = 9;    
    }

    for(map<char, int>::iterator it = m.begin(); it != m.end(); ++it){
        cout << it->first << ", " << it->second << endl;
    }
}

string change(string &str, map<char, int> & m)
{
    //string passwd = str;
    
    for(int i = 0; i < str.size(); ++i){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = m[str[i]];
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            if(str[i] == 'Z')
                str[i] = 'a';
            else{
                str[i] = str[i]-'A' + 'a' + 1;
            }
        }
    } 
    
    return str;
}


int main()
{
    string str;
    
    map<char, int> m;
    init(m);
    
    while(getline(cin, str)){
        string passwd = change(str, m);
        cout << passwd << endl;
    }
    
    
    return 0;
}
