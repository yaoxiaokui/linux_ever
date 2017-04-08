/*************************************************************************
	> File Name: myallocator.h
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jun 2016 03:23:24 PM CST
 ************************************************************************/

//#ifndef _MYALLOCATOR_H
//#define _MYALLOCATOR_H

#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>

using namespace std;

namespace MY
{
    //分配大小为size * (sizeof(T))的内存空间
    template<typename T>
    inline T * _allocate(ptrdiff_t size, T *){
        //以new函数的形式调用
        T *temp = (T *)(::operator new((size_t)size * sizeof(T)));

        //以运算符的形式调用
        //T *temp = new T[size];

        if(temp == NULL){
            cerr << "out of memory" << endl;
            exit(1);
        }

        return temp;
    }


    //释放内存空间
    template<typename T>
    inline void _deallocate(T *buffer){
        ::operator delete(buffer);//以函数的形式释放内存
        //delete []buffer;
    }

    template<typename T1, typename T2>
    inline void _construct(T1 * p, const T2 & value){
        new(p) T1(value);
    }

    template<typename T>
    inline void _destory(T *ptr){
        ptr->~T();
    }


    //类定义
    class allocator{
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;

        pointer allocate()

        
    };
};



//#endif
