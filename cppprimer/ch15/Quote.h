/*************************************************************************
	> File Name: Quote.h
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Apr 2017 03:01:24 PM CST
 ************************************************************************/

#ifndef _QUOTE_H
#define _QUOTE_H

#include <string>
using std::string;

class Quote{
public:
    Quote() = default;
    Quote(const std::string & book, double sales_price):
          bookNo(book), price(sales_price){}
    std::string isbn() const;
    virtual double net_price(std::size_t n) const;
    virtual ~Quote() = default;

private:
    std::string bookNo;
protected:
    double price = 0.0;
};

std::string Quote::isbn() const
{
    return bookNo;
}

double Quote::net_price(std::size_t n) const
{
    return price * n;
}

#endif

