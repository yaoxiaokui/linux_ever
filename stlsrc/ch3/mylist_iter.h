/*************************************************************************
	> File Name: mylist_iter.h
	> Author: 
	> Mail: 
	> Created Time: 2015年12月19日 星期六 16时18分16秒
 ************************************************************************/

#ifndef _MYLIST_ITER_H
#define _MYLIST_ITER_H
#include "mylist.h"

template<class Item>
class ListIter{
    Item * ptr;
    ListIter(Item * p = 0):ptr(p){}

    Item & operator*()const {return *ptr;}
    Item * operator->() const {return ptr;}

    ListIter &operator++(){
        ptr = ptr->next();
        return *this;
    }

    ListIter operator++(int){
        ListIter temp = *this;
        ++*this;
        return temp;
    }

    bool operator==(const ListIter & rhs) const{
        return ptr == rhs.ptr;
    }
    bool operator!=(const ListIter & rhs) const{
        return ptr != rhs.ptr;
    }
};
#endif
