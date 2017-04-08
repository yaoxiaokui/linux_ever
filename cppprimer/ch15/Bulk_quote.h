/*************************************************************************
	> File Name: Bulk_quote.h
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Apr 2017 03:07:54 PM CST
 ************************************************************************/

#ifndef _BULK_QUOTE_H
#define _BULK_QUOTE_H

#include <string>

class Bulk_quote : public Quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &, double, std::size_t, double);

    double net_price(std::size_t cnt) const override;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

Bulk_quote::Bulk_quote(const std::string & book, double p, std::size_t qty, double disc):
                        Quote(book, p), min_qty(qty), discount(disc)
{

}


double Bulk_quote::net_price(std::size_t cnt) const
{
    if(cnt >= min_qty)
        return cnt * discount * price;
    else
        return cnt * price;
}
#endif
