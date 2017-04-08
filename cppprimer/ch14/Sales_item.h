/*************************************************************************
	> File Name: Sales_item.h
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Mar 2017 02:30:44 PM CST
 ************************************************************************/

#ifndef _SALES_ITEM_H
#define _SALES_ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Sales_item
{
friend ostream & operator<<(ostream & out, const Sales_item & item);
friend istream & operator>>(istream & in, Sales_item & item);
friend Sales_item operator+(const Sales_item & item1, const Sales_item & item2);
friend bool operator==(const Sales_item & item1, const Sales_item & item2);
friend bool operator!=(const Sales_item & item1, const Sales_item & item2);
friend bool operator<(const Sales_item & item1, const Sales_item & item2);
friend bool operator>(const Sales_item & item1, const Sales_item & item2);


private:
    string ISBN;
    int count;
    double totalprice;
public:

    Sales_item(){}
    Sales_item(istream & in);
    
    //Sales_item(const Sales_item & item);
    Sales_item & operator+=(const Sales_item & item);
    string isbn() const;


    char & operator[](int i);
    const char & operator[](int i) const;
};

const char & Sales_item::operator[](int i) const
{
    return ISBN[i];
}

char & Sales_item::operator[](int i)
{
    return ISBN[i];
}


Sales_item::Sales_item(istream & in)
{
    in >> ISBN >> count >> totalprice;
}

Sales_item & Sales_item::operator+=(const Sales_item & item)
{
    count += item.count;
    totalprice += item.totalprice;

    return *this;
}

bool operator>(const Sales_item & item1, const Sales_item & item2)
{
    return !(item1 < item2);
}

bool operator<(const Sales_item & item1, const Sales_item & item2)
{
    if(item1.ISBN < item2.ISBN)
        return true;
    else if(item1.ISBN == item2.ISBN){
        if(item1.count < item2.count)
            return true;
        else if(item1.totalprice < item2.totalprice)
            return true;
        else
            return false;
    }
    else
        return false;
}


bool operator!=(const Sales_item & item1, const Sales_item & item2)
{
    return !(item1 == item2);
}

bool operator==(const Sales_item & item1, const Sales_item & item2)
{
    if(item1.ISBN == item2.ISBN && item1.count == item2.count && item1.totalprice == item2.totalprice)
        return true;

    return false;
}


Sales_item operator+(const Sales_item & item1, const Sales_item & item2)
{
    Sales_item item;
    item.ISBN = item1.ISBN;
    item.count = item1.count + item2.count;
    item.totalprice = item1.totalprice + item2.totalprice;

    return item;
}

istream & operator>>(istream & in, Sales_item & item)
{
    in >> item.ISBN >> item.count >>  item.totalprice;
    return in;
}


ostream & operator<<(ostream & out, const Sales_item & item)
{
    out << "item: " << item.ISBN << ", count: " << item.count << ", totalprice: " << item.totalprice << endl;
    return out;
}

string Sales_item::isbn() const
{
    return ISBN;
}


#endif
