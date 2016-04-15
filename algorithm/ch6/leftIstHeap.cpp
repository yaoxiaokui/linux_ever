/*************************************************************************
	> File Name: leftIstHeap.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月15日 星期五 10时14分04秒
 ************************************************************************/

#include <iostream>
using namespace std;

/***************************************************************
*
*  类的名称：左式堆
*
***************************************************************/

template<typename Comparable>
class LeftistHeap
{
    public:
        LeftistHeap();//构造函数
        LeftistHeap(const LeftistHeap & rhs);//复制构造函数
        ~LeftistHeap();//析构
        
        void preOrderPrint();//前序遍历该树输出
        bool isEmpty() const;//判断该树是否为空
        const Comparable & findMin() const;//找到最小值
        void deleteMin();//删除最小元素 
        void deleteMin(Comparable & minItem);//删除最小元素，并以引用的方式返回该最小元素

    private:
        //树的节点数据结构
        struct LeftistNode{
            Comparable element;//节点的元素
            LeftistNode * left;//节点的左孩子
            LeftistNode * right;//节点的右孩子 
            int npl;//节点的零路径长

            LeftistNode(const Comparable & e, LeftistNode * lt = NULL, LeftistNode * rt = NULL, int np = 0):
            element(e), left(lt), right(rt), npl(np){}
        };

        LeftistNode * root;//树的根节点
    private:
        LeftistNode * merge(LeftistNode * h1, LeftistNode * h2);//合并两个左式
        void preOrderPrint(const LeftistNode * node);//前序遍历该树
};

/****************************************************************
*   函数名称：deleteMin(Comparable & minItem) 
*   功能描述: 删除最小元素,并以引用的方式返回该最小元素
*   参数列表: minItem将最小元素赋值给该引用 
*   返回结果：void
*****************************************************************/
template<typename Comparable>
void LeftistHeap<Comparable>::deleteMin(Comparable & minItem)
{
    
}

/****************************************************************
*   函数名称：deleteMin() 
*   功能描述: 删除最小元素
*   参数列表: 无 
*   返回结果：void
*****************************************************************/
template<typename Comparable>
void LeftistHeap<Comparable>::deleteMin()
{
    
}

/****************************************************************
*   函数名称：findMin() const
*   功能描述: 查找该树的最小元素
*   参数列表: 无 
*   返回结果：如果找到该树的最小元素，则返回该最小元素
*****************************************************************/
template<typename Comparable>
const Comparable & LeftistHeap<Comparable>::findMin() const
{
    if(isEmpty()){
        cout << "The tree is empty." << endl;
        LeftistNode node;
        return node;//返回一个空对象 
    }

    return root->element;
}

/****************************************************************
*   函数名称：isEmpty() const
*   功能描述: 判断该树是否为空 
*   参数列表: 无 
*   返回结果：如果为空，则返回true；否则返回false
*****************************************************************/
template<typename Comparable>
bool LeftistHeap<Comparable>::isEmpty() const
{
    return root == NULL;
}

/****************************************************************
*   函数名称：preOrderPrint(const LeftistNode * node)
*   功能描述: 前序遍历该树 
*   参数列表: node是当前树节点
*   返回结果：void
*****************************************************************/
template<typename Comparable>
void LeftistHeap<Comparable>::preOrderPrint(const LeftistNode * root)
{
    if(isEmpty()){
        cout << "The tree is empty." << endl;
        return;
    }

    if(root != NULL){
        cout << root->element << " ";
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }

}

/****************************************************************
*   函数名称：preOrderPrint()
*   功能描述: 前序遍历该树输出 
*   参数列表: 无
*   返回结果：void
*****************************************************************/
template<typename Comparable>
void LeftistHeap<Comparable>::preOrderPrint()
{
    preOrderPrint(root);
}

/****************************************************************
*   函数名称：~LeftistHeap()
*   功能描述: 析构函数 
*   参数列表: 无
*   返回结果：无
*****************************************************************/
template<typename Comparable>
LeftistHeap<Comparable>::~LeftistHeap()
{
    
}

/****************************************************************
*   函数名称：LeftistHeap(const LeftistHeap & rhs)
*   功能描述: 复制构造函数 
*   参数列表: rhs是要拷贝的左式树 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
LeftistHeap<Comparable>::LeftistHeap(const LeftistHeap & rhs)
{
    
}



//测试主函数
int main()
{
    
    return 0;
}
