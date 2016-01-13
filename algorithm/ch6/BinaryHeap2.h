/*************************************************************************
	> File Name: BinaryHeap.h
	> Author: 
	> Mail: 
	> Created Time: 2016年01月09日 星期六 14时28分57秒
 ************************************************************************/

#ifndef _BINARYHEAP_H
#define _BINARYHEAP_H

#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

template<class Comparable>
class BinaryHeap{
    public:
        explicit BinaryHeap(int capacity = 100):currentSize(capacity){}
        explicit BinaryHeap(const vector<Comparable> & items);

        bool isEmpty() const;
        const Comparable & findMin() const;
        
        void insert(const Comparable & x);
        void deleteMin();
        void deleteMin(Comparable & minItem);
        void makeEmpty();
        void output();
        void outputTree();
    private:
        int currentSize;
        vector<Comparable> array;
        
        void buildHeap();
        void percolateDown(int hole);
};


template<class Comparable>
BinaryHeap<Comparable>::BinaryHeap(const vector<Comparable> & items):array(items.size() + 10), currentSize(items.size())
{
    for (int i = 0; i < items.size(); ++i)
        array[i + 1] = items[i];

    buildHeap();
}

template<class Comparable>
void BinaryHeap<Comparable>::buildHeap()
{
    for (int i = currentSize/2; i > 0; i--){
        percolateDown(i);
    }
}
/*********************************/
void output_space(int n)
{
    for (int i = 0; i < n; ++i)
        cout << " ";
}

void output_left()
{
    cout << '\/';
}
void output_right()
{
    cout << '\\';
}

template<class Comparable>
void output_node(vector<Comparable> & v, int num, int len)
{
    output_space(len);
    cout << v[num];

    if(num == 1){
        output_left();
        output_space(1);
        output_right();
        cout << endl;
    }

    output_space(len-4);
    cout << v[num*2];
    output_space(8);
    cout << v[num*2+1];

    output_left();
    output_space(1);
    output_right();

    output_space(8);
    output_left();
    output_space(1);
    output_right();
}

template<class Comparable>
void output_heap(vector<Comparable> & v, int num, int size)
{
    if(num == size)
        return;

    int underline_len = 16;

    cout << "num is " << num << ", size is " << size << endl;

    output_node(v, num, size);
    cin.get();
    output_heap(v, num*2, size-4);
    output_heap(v, num*2 + 1, size + 4);
}

template<class Comparable>
void BinaryHeap<Comparable>::outputTree()
{
    std::cout << "堆：" << endl;
    output_heap(array, 1, currentSize/2 * 4); 
    cout << endl;
}

/*********************************/
template<class Comparable>
void BinaryHeap<Comparable>::output()
{
    std::cout << "堆：";
    for (int i = 0; i < currentSize; ++i)
        cout << array[i+1] << " ";
    cout << endl;
}

template<class Comparable>
void BinaryHeap<Comparable>::insert(const Comparable & x)
{
    if(currentSize == array.size()-1)
        array.resize(array.size()*2);
    
    int hole = ++currentSize;

    for (; hole > 1 && x < array[hole/2]; hole /= 2)
        array[hole] = array[hole/2];

    array[hole] = x;
}
/*删除最小值，也就是删除堆的根*/
template<class Comparable>
void BinaryHeap<Comparable>::deleteMin()
{
    if(isEmpty()){
        cout << "这是一个空树。" << endl;
        return;
    }
    
    array[1] = array[currentSize--];
    percolateDown(1);
}

/*删除最小值，也就是删除堆的根, 并得到该最小值保存到minItem中*/
template<class Comparable>
void BinaryHeap<Comparable>::deleteMin(Comparable & minItem)
{
    if(isEmpty()){
        cout << "这是一个空树。" << endl;
        return;
    }
    minItem = array[1]; 
    array[1] = array[currentSize--];
    percolateDown(1);
}

template<class Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)
{
    int child;
    Comparable tmp = array[hole];
    for (; hole * 2 <= currentSize; hole = child){
        child = hole * 2;//left child node

        if(child != currentSize && array[child+1] < array[child]){//right child node < left child node
            child++;
        }

        if(array[child] < tmp)//less child node < parent node
            array[hole] = array[child];//将最小的子结点放在父结点的位置
        else
            break;
    }

    array[hole] = tmp;
}


#endif
