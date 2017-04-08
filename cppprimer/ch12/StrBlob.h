/*************************************************************************
	> File Name: StrBlob.h
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Mar 2017 08:22:06 PM CST
 ************************************************************************/

#ifndef _STRBLOB_H
#define _STRBLOB_H

#include <string>
#include <vector>

class StrBlob{
public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string & t) { data->push_back(t); }
    void pop_back();

    std::string & front();
    std::string & back();

    std::string & front() const;
    std::string & back() const;

private:
    std::shared_ptr<std::vector<std::string>> data;

    void check(size_type i, const std::string & msg) const;

};



StrBlob::StrBlob():data(make_shared<vector<string> > ())
{
    
}

StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string> >(il))
{

}

void StrBlob::check(size_type i, const string & msg) const
{
    if(i >= data->size())
        throw out_of_range(msg);
}

string & StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string & StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string & StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

string & StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}



#endif
