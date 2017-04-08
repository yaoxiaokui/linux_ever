/*************************************************************************
	> File Name: stringstream.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Mar 2017 05:07:34 PM CST
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


struct PersonInfo{
    string name;
    vector<string> phones;
};

void print(vector<PersonInfo> & persons)
{
    for(int i = 0; i < persons.size(); ++i){
        cout << persons[i].name << ": ";
        for(int j = 0; j < persons[i].phones.size(); ++j)
            cout << persons[i].phones[j] << " ";
        cout << endl;
    }
}

int main()
{
    string line, word;
    vector<PersonInfo> persons;

    while(getline(cin, line)){
        istringstream istring(line);

        string newstring;
        ostringstream ostring;

        PersonInfo person;

        istring >> person.name;
        ostring << person.name;
        cout << "newstring = " << ostring.str() << endl;

        while(istring >> word){
            person.phones.push_back(word);
        }

        persons.push_back(person);

    }

    
    print(persons);


    return 0;
}
