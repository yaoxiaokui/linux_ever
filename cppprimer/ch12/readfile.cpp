/*************************************************************************
	> File Name: readfile.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Mar 2017 09:26:58 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <map>
using namespace std;


class QueryResult{

friend ostream & print(ostream & os, const QueryResult &);
public:
    QueryResult(string s, 
                shared_ptr<set<line_no>> p, 
                shared_ptr<vector<string>> f):sought(s), lines(p), file(f){}

private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};


class TextQuery{
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;

private:
    std::shared_ptr<std::vector<std::string> > file;
    
    std::map<string, shared_ptr<std::set<line_no>> > wm;


};

QueryResult TextQuery::query(const string & sought) const
{
    
}

TextQuery::TextQuery(ifstream & is):file(new vector<string>)
{
    string text;
    while(getline(is, text)){
        file->push_back(text);
        int n = file->size() - 1;//保存当前行号

        istringstream line(text);
        string word;
        while(line >> word){
            auto & lines = wm[word];
            if(!lines)
                lines.reset(new set<line_no>);

            lines->insert(n);
        }
    }
}

void runQueries(ifstream & infile)
{
    TextQuery tq(infile);

    while(true){
        cout << "enter word to look for, or q to quit: ";
        string s;

        if(!(cin >> s) || s == 'q')
            break;

        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, char * argv[])
{
    vector<string> lines;
    string str;

    ifstream fin(argv[1]);

    while(fin >> str){
        lines.push_back(str);
    }
    


    return 0;
}
