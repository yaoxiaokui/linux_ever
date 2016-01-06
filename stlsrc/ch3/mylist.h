/*************************************************************************
	> File Name: mylist.h
	> Author: 
	> Mail: 
	> Created Time: 2015年12月19日 星期六 16时11分55秒
 ************************************************************************/

#ifndef _MYLIST_H
#define _MYLIST_H
#include <iostream>

template<class T>
class List{
    public:
        void insert_front(T value);
        void insert_end(T value);
        void display(std::ostream &os = std::cout) const;
    private:
        ListItem<T> * _end;
        ListItem<T> * _front;
        long _size;
};

template<class T>
class ListItem{

    public:
        T value() {return _value;}
        ListItem * next() const {return _next;}

    private:
        T _value;
        ListItem * _next;
};

void List::display(std::ostream &os == std::cout) const{
    ListItem * p = _front;
    while(p != NULL){
        os << *p << " ";
        p = p->_next;
    }
    os << std::endl;
}
#endif
