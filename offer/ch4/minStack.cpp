/*************************************************************************
	> File Name: minStack.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Jun 2016 11:31:22 AM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;


template<typename T>
class StackWithMin
{
private:
    stack<T> dataStack;
    stack<T> minStack;

public:
    void push(const T & element);
    void pop();
    const T & min() const;

};


//压入
template<typename T>
void StackWithMin<T>::push(const T &element)
{
    dataStack.push(element);


    //当向minStack中压入第一个元素或element小于minStack中的最小元素的时候
    if(minStack.empty() || element < minStack.top())  
        minStack.push(element);
    else
        minStack.push(minStack.top());
}

//弹出
template<typename T>
void StackWithMin<T>::pop()
{
    if(dataStack.empty() || minStack.empty())
        return;

    dataStack.pop();
    minStack.pop();
}

//获得栈的最小值
template<typename T>
const T & StackWithMin<T>::min() const
{
    if(!minStack.empty())
        return minStack.top();
}



//主测试函数
int main()
{
    StackWithMin<int> stack;

    stack.push(3);
    stack.push(4);
    stack.push(2);
    stack.push(1);

    cout << "3, 4, 2, 1 , the min element is " << stack.min() << endl;

    stack.pop();
    stack.pop();

    cout << "3, 4, the min element is " << stack.min() << endl;

    stack.push(0);
    
    cout << "3, 4, 0, the min element is " << stack.min() << endl;


    return 0;
}
