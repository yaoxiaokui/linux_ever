/*************************************************************************
	> File Name: useBook.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Apr 2017 03:52:18 PM CST
 ************************************************************************/

#include <iostream>
#include "./Quote.h"
#include "./Bulk_quote.h"
using namespace std;

void print(Quote & book, std::size_t n)
{
    cout << book.isbn() << ", price = " << book.net_price(n) << endl;
}

int main()
{
    Quote base1("base1", 10);
    print(base1, 3);

    Bulk_quote bulkBook1("bulkBook1", 10, 4, 0.8);
    print(bulkBook1, 4);

    Bulk_quote bulkBook2("bulkBook1", 10, 12, 0.8);
    print(bulkBook2, 4);



    return 0;
}

