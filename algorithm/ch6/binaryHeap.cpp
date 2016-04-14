/*************************************************************************
	> File Name: binaryHeap.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月14日 星期四 11时37分43秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;



/******************************************
*   类的名称：二叉堆
******************************************/

template<typename Comparable>
class BinaryHeap
{
    public:
        explicit BinaryHeap(int capacity = 100):array(capacity), currentSize(0){}
        explicit BinaryHeap(const vector<Comparable> & items);

        bool isEmpty() const;//判断二叉堆是否为空
        const Comparable & findMin() const;//查找最小元素
        
        void insert(const Comparable & x);//插入元素x
        void deleteMin();//删除最小元素
        void deleteMin(Comparable & minItem);//删除最小元素，并以引用的方式返回该最小元素
        void makeEmpty();//清空该二叉堆 
        void print() const;//打印该堆元素

    private:
        vector<Comparable> array;//存储二叉堆的节点 
        int currentSize;//当前二叉堆中的节点数目
    private:
        void buildHeap();//将元素移动到合适的位置
        void percolateDown(int hole);//下移动
};

/****************************************************************
*   函数名称：print() const
*   功能描述: 打印该堆元素 
*   参数列表: 无 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
void BinaryHeap<Comparable>::print() const
{
    cout << "二叉堆的元素: " << endl;
    for(int i = 1; i <= currentSize; ++i)
        cout << array[i] << " ";
    cout << endl;
}

/****************************************************************
*   函数名称：BinaryHeap(const vector<Comparable> & items)
*   功能描述: 构造函数
*   参数列表: items 是构造二叉堆需要的数据
*   返回结果：无
*****************************************************************/
template<typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(const vector<Comparable> & items):array(items.size()+10), currentSize(items.size())
{
    for(unsigned i = 0; i < items.size(); ++i)
        array[i+1] = items[i];

    buildHeap();
}
/****************************************************************
*   函数名称：buildHeap()
*   功能描述: 将元素移动到合适的位置，满足堆序
*   参数列表: 无
*   返回结果：void
*****************************************************************/
template<typename Comparable>
void BinaryHeap<Comparable>::buildHeap()
{
    for(int i = currentSize / 2; i > 0; --i)
        percolateDown(i);
}

/****************************************************************
*   函数名称：findMin()
*   功能描述: 查找最小元素
*   参数列表: 无
*   返回结果：返回最小元素的引用
*****************************************************************/
template<typename Comparable>
const Comparable & BinaryHeap<Comparable>::findMin() const
{
   return array[1]; 
}

/****************************************************************
*   函数名称：insert(const Comparable & x)
*   功能描述: 删除最小元素
*   参数列表: 无
*   返回结果：void 
*****************************************************************/
template<typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable & x)
{
    if(currentSize == array.size()-1)
        array.resize(2 * array.size());//扩大堆中数组的容量

    //获得空穴的位置
    int hole = ++currentSize;

    //上滤
    for(; hole > 1 && x < array[hole/2]; hole /= 2)
        array[hole] = array[hole/2];
    //将x插入到合适的位置
    array[hole] = x;
}

/****************************************************************
*   函数名称：deleteMin()
*   功能描述: 删除最小元素
*   参数列表: 无
*   返回结果：void 
*****************************************************************/
template<typename Comparable>
void BinaryHeap<Comparable>::deleteMin()
{
    if(isEmpty()){
        cout << "BinaryHeap is empty." << endl;
        return;
    }

    array[1] = array[currentSize];//将最后一个元素移动到最小元素的位置
    currentSize--;//元素总数减去1
    //将最后一个元素移动到合适的位置
    percolateDown(1); 
}

/****************************************************************
*   函数名称：percolateDown(int hole)
*   功能描述: 将array(hole)处的值向下移动 
*   参数列表: hole为堆中元素的位置标号
*   返回结果：void 
*****************************************************************/
template<typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)
{
    int child;
    //先保存array[hole]的值
    Comparable temp = array[hole];

    for(; hole * 2 <= currentSize; hole = child){
        child = hole * 2;

        //child != currentSize,表明此时空穴有右儿子
        //array[child] > array[child+1] 表明此时空穴有右儿子小于左儿子
        if(child != currentSize && array[child] > array[child+1])
            child++;//此时child表示为空穴的右儿子

        //空穴的右儿子小于array[hole]
        if(array[child] < temp)
            array[hole] = array[child];
        else
            break;
    }

    array[hole] = temp;
}
/****************************************************************
*   函数名称：deleteMin(Comparable & minItem)
*   功能描述: 删除最小元素
*   参数列表: minItem 将最小元素赋值给引用minItem
*   返回结果：void 
*****************************************************************/
template<typename Comparable>
void BinaryHeap<Comparable>::deleteMin(Comparable & minItem)
{
    if(isEmpty()){
        cout << "binaryHeap is empty." << endl;
        return;
    }

    minItem = array[1];

    array[1] = array[currentSize--];
    percolateDown(1);
}

/****************************************************************
*   函数名称：makeEmpty()
*   功能描述: 情况二叉堆
*   参数列表: 无
*   返回结果：void 
*****************************************************************/
template<typename Comparable>
void BinaryHeap<Comparable>::makeEmpty()
{
    currentSize = 0;
}

/****************************************************************
*   函数名称：isEmpty()
*   功能描述: 判断二叉堆是否为空
*   参数列表: 无
*   返回结果：如果为空，则返回true，否则返回false
*****************************************************************/
template<typename Comparable>
bool BinaryHeap<Comparable>::isEmpty() const
{
    return currentSize == 0;
}




//测试主函数
int main()
{
    srand(unsigned(time(0)));
    BinaryHeap<int> binaryHeap;

    vector<int> v;

    for(int i = 0; i < 10; ++i)
        v.push_back(rand() % 10);
    cout << "v: ";
    for(int i = 0; i < 10; ++i)
        cout << v[i] << " ";
    cout << endl;
    

    for(int i = 0; i < 10; ++i)
        binaryHeap.insert(v[i]);

    binaryHeap.print();


    for(int i = 0; i < 12; i++){
        int minVal = 0;
        binaryHeap.deleteMin(minVal);
        cout << "删除最小元素："  << minVal << endl;
        binaryHeap.print();
    }

    cout << "*****************************************" << endl;
    cout << "测试第二个构造函数: " << endl;
    BinaryHeap<int> binaryHeap2(v);
    binaryHeap2.print();

    for(int i = 0; i < 12; i++){
        int minVal = 0;
        binaryHeap2.deleteMin(minVal);
        cout << "删除最小元素："  << minVal << endl;
        binaryHeap2.print();
    }


    return 0;
}
