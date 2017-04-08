/*************************************************************************
    > File Name: BinarySearchTree.cpp
    > Author: 
    > Mail: 
    > Created Time: 2016年04月06日 星期三 17时19分47秒
 ************************************************************************/
 
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <queue>
using namespace std;
 
template<typename Comparable>
class BinarySearchTree{
    public:
        BinarySearchTree(){root = NULL;}
        BinarySearchTree(vector<int> & v);
        BinarySearchTree(const BinarySearchTree & rhs);
        BinarySearchTree & operator=(const BinarySearchTree & rhs);//赋值运算符重载
        ~BinarySearchTree();
 
        //求二叉树的深度
        int TreeDepth() const;
        void topToBottonPrintTree() const; //从上到下打印二叉树
        void topToBottonPrintTree2() const; //从上到下打印二叉树

        //前序遍历
        void preOrderPrintTree() const;
        //中序遍历
        void inOrderPrintTree() const;
        //后序遍历
        void postOrderPrintTree() const;
 
        void makeEmpty();//清空该二叉查找树
        void insert(const Comparable & x);//插入结点
        void remove(const Comparable & x);//移除结点值为x的结点
 
 
        Comparable findMin() const;//查找最小值
        Comparable findMax() const;//查找最大值
        bool contains(const Comparable & x) const;//判断该二叉查找树是否包含值为x的结点
        bool isEmpty() const;//判断该二叉查找树是否为空 
    private:
        //树结点的数据结构
        struct BinaryNode{
            Comparable element;
            BinaryNode * left;
            BinaryNode * right;
            int num;//相同值的结点出现的次数
            BinaryNode(const Comparable & e, BinaryNode* lt, BinaryNode* rt, int n):element(e), left(lt), right(rt), num(n){}
        };
 
        BinaryNode* root;
    private:
        //求二叉树的深度
        int TreeDepth(BinaryNode * root) const;

        void topToBottonPrintTree2(BinaryNode * root, int level) const; //从上到下打印二叉树
    private:
        void insert(const Comparable & x, BinaryNode * &t) const;
 
        void preOrder(BinaryNode * t) const;//前序遍历
        void inOrder(BinaryNode * t) const;//中序遍历
        void postOrder(BinaryNode * t) const;//后序遍历

        void deleteNode(BinaryNode * t);//释放结点t
        Comparable &findMin(BinaryNode * node) const;
        Comparable &findMax(BinaryNode * node) const;
        bool contains(const Comparable & x, BinaryNode * t) const;//判断该二叉查找树是否包含值为x的结点
        BinaryNode *clone(BinaryNode * t) const{
            if(t == NULL)
                return NULL;
 
            return new BinaryNode(t->element, clone(t->left), clone(t->right), t->num);
        }
 
 
};
 
/****************************************************************
*   函数名称：topToBottonPrintTree2()
*   功能描述: 从上到下打印二叉树,按层打印
*   参数列表: void
*   返回结果：无
*****************************************************************/
template<typename Comparable>
void BinarySearchTree<Comparable>::topToBottonPrintTree2() const
{
    int level = TreeDepth();

    cout << "按层遍历二叉树: ";

    for(int i = 1; i <= level; ++i)
        topToBottonPrintTree2(root, i);

    cout << endl;
}

/****************************************************************
*   函数名称：topToBottonPrintTree2()
*   功能描述: 从上到下打印二叉树,按层打印
*   参数列表: void
*   返回结果：无
*****************************************************************/
template<typename Comparable>
void BinarySearchTree<Comparable>::topToBottonPrintTree2(BinaryNode * root, int level) const
{
    if(root == NULL)
        return;

    if(level == 1)
        cout << root->element << " ";
    else if(level > 1){
        topToBottonPrintTree2(root->left, level-1);
        topToBottonPrintTree2(root->right, level-1);
    }
}

/****************************************************************
*   函数名称：topToBottonPrintTree()
*   功能描述: 从上到下打印二叉树,按层打印
*   参数列表: void
*   返回结果：无
*****************************************************************/
template<typename Comparable>
void BinarySearchTree<Comparable>::topToBottonPrintTree() const
{
    //如果为空，直接返回
    if(isEmpty()){
        cout << "The BinarySearchTree is empty." << endl;
        return;
    }
 
    queue<BinaryNode *> nodeQue;
    nodeQue.push(root);
 
    //直到队列不为空
    while(!nodeQue.empty()){
        BinaryNode * pNode = nodeQue.front();
        nodeQue.pop();
 
        //输出结点值
        cout << pNode->element << " ";
 
        //将pNode指向结点的左子节点压入到队列
        if(pNode->left)
            nodeQue.push(pNode->left);
 
        //将pNode指向结点的右子节点压入到队列
        if(pNode->right)
            nodeQue.push(pNode->right);
    }
 
    cout << endl;
 
}
 
/****************************************************************
*   函数名称：TreeDepth
*   功能描述: 求二叉树的深度
*   参数列表: root指向当前结点 
*   返回结果：返回root为根结点的树的高度
*****************************************************************/
template<typename Comparable>
int BinarySearchTree<Comparable>::TreeDepth() const
{
    if(root == NULL)
        return 0;
 
    return TreeDepth(root);
}
 
/****************************************************************
*   函数名称：TreeDepth
*   功能描述: 求二叉树的深度
*   参数列表: root指向当前结点 
*   返回结果：返回root为根结点的树的高度
*****************************************************************/
template<typename Comparable>
int BinarySearchTree<Comparable>::TreeDepth(BinaryNode * root) const
{
    if(root == NULL)
        return 0;
 
    int leftTreeDepth = TreeDepth(root->left);
    int rightTreeDepth = TreeDepth(root->right);
 
    return leftTreeDepth > rightTreeDepth ? (leftTreeDepth+1) : (rightTreeDepth+1);
}
 
/****************************************************************
*   函数名称：BinarySearchTree(const BinarySearchTree & rhs)
*   功能描述: 该二叉查找树的复制构造函数
*   参数列表: rhs 要复制的二叉查找树 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree & rhs)
{
    root = clone(rhs.root);
}
 
/****************************************************************
*   函数名称：BinarySearchTree(const BinarySearchTree & rhs)
*   功能描述: 该二叉查找树的赋值运算符
*   参数列表: rhs 要复制的二叉查找树 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
BinarySearchTree<Comparable> & BinarySearchTree<Comparable>::operator=(const BinarySearchTree & rhs)
{
    if(this != &rhs){
        makeEmpty();
        root = clone(rhs.root);
    }
 
    return *this;
}
 
/****************************************************************
*   函数名称：contains(const Comparable & x)const
*   功能描述: 判断该二叉查找树是否含有值为x的结点 
*   参数列表: 无
*   返回结果：如果有值为x的结点，则返回true;
*             如果没有值为x的结点，则返回false;
*****************************************************************/
template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & x) const
{
    if(isEmpty())
        return false;
    else
        return contains(x, root); 
}
 
template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & x, BinaryNode * t) const
{
    if(t == NULL)
        return false;
 
    if(x == t->element)
        return true;
    else if(x > t->element)
        return contains(x, t->right);
    else if(x < t->element)
        return contains(x, t->left);
}
 
/****************************************************************
*   函数名称：findMax()const
*   功能描述: 查找树的最大值 
*   参数列表: 无
*   返回结果：结点值的引用
*****************************************************************/
template<typename Comparable>
Comparable BinarySearchTree<Comparable>::findMax() const
{
    if(!isEmpty())
        return findMax(root); 
}
 
/****************************************************************
*   函数名称：findMax(BinaryNode *node)const
*   功能描述: 查找树的最大值 
*   参数列表: 无
*   返回结果：结点值的引用
*****************************************************************/
template<typename Comparable>
Comparable & BinarySearchTree<Comparable>::findMax(BinaryNode * node) const
{
    if(node->right== NULL)
        return node->element;
    else 
        return findMax(node->right);
}
 
/****************************************************************
*   函数名称：findMin()const
*   功能描述: 查找树的最小值 
*   参数列表: 无
*   返回结果：结点值的引用
*****************************************************************/
template<typename Comparable>
Comparable BinarySearchTree<Comparable>::findMin() const
{
    if(!isEmpty())
        return findMin(root); 
}
 
/****************************************************************
*   函数名称：findMin(BinaryNode *node)const
*   功能描述: 查找树的最小值 
*   参数列表: 无
*   返回结果：结点值的引用
*****************************************************************/
template<typename Comparable>
Comparable & BinarySearchTree<Comparable>::findMin(BinaryNode * node) const
{
    if(node->left == NULL)
        return node->element;
    else 
        return findMin(node->left);
}
 
/****************************************************************
*   函数名称：BinarySearchTree(vector<int> &)
*   功能描述: 构造函数
*   参数列表: v 用于构造二叉查找树的数据序列
*   返回结果：无
*****************************************************************/
template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(vector<int> & v)
{
    root = NULL;//必须初始化,否则析构的时候会出错
 
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        insert(*it); 
}
 
/****************************************************************
*   函数名称：~BinarySearchTree()
*   功能描述: 析构函数 
*   参数列表: 无 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
   //deleteNode(root); 
    makeEmpty();//两种方式都可以
}
 
/****************************************************************
*   函数名称：deleteNode(BinaryNode *t)
*   功能描述: 释放结点 
*   参数列表: 要释放结点的指针 
*   返回结果：void
*****************************************************************/
template<typename Comparable>
void BinarySearchTree<Comparable>::deleteNode(BinaryNode * t)
{
    //后序遍历的方式释放所有结点 
    if(t != NULL){
        deleteNode(t->left);
        deleteNode(t->right);
        //cout << "t->element = " << t->element << endl;
        delete t;
    }
}
 
 
/****************************************************************
*   函数名称：isEmpty() const
*   功能描述: 判断该二叉查找树是否为空 
*   参数列表: 无 
*   返回结果：如果该树为空，则返回true；
*             如果该树为不为空，则返回false
*****************************************************************/
template<typename Comparable>
bool BinarySearchTree<Comparable>::isEmpty()const
{
    return (root == NULL) ? true : false;
}
 
 
/****************************************************************
*   函数名称：makeEmpty() 
*   功能描述: 将该二叉查找树清空 
*   参数列表: 无 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty()
{
    deleteNode(root);//移除所有结点
    root = NULL;
}
 
 
/****************************************************************
*   函数名称：preOrderPrintTree() const
*   功能描述: 前序遍历 
*   参数列表: 无 
*   返回结果：void
*****************************************************************/
template<typename Comparable>
void BinarySearchTree<Comparable>::preOrderPrintTree() const
{
    cout << "前序遍历: ";
    preOrder(root); 
    cout << endl;
}
 
/****************************************************************
*   函数名称：preOrder(BinaryNode * t) const
*   功能描述: 前序遍历
*   参数列表: 当前结点的指针 
*   返回结果：void
*****************************************************************/
template<typename Comparable>
void BinarySearchTree<Comparable>::preOrder(BinaryNode * t) const
{
    if(t != NULL){
 
        for(int i = 0; i < t->num; ++i)
            cout << t->element << " ";//打印父结点，可能有多个值
 
        preOrder(t->left);//打印左子树
        preOrder(t->right);//打印右子树
    }
}
 
/****************************************************************
*   函数名称：inOrderPrintTree() const
*   功能描述: 中序遍历 
*   参数列表: 无 
*   返回结果：void
*****************************************************************/
template<typename Comparable>
void BinarySearchTree<Comparable>::inOrderPrintTree() const
{
    cout << "中序遍历: ";
    inOrder(root); 
    cout << endl;
}
 
/****************************************************************
*   函数名称：inOrder(BinaryNode * t) const
*   功能描述: 中序遍历
*   参数列表: 当前结点的指针 
*   返回结果：void
*****************************************************************/
template<typename Comparable>
void BinarySearchTree<Comparable>::inOrder(BinaryNode * t) const
{
    if(t != NULL){
        inOrder(t->left);//打印左子树
 
        for(int i = 0; i < t->num; ++i)
            cout << t->element << " ";//打印父结点，可能有多个值
 
        inOrder(t->right);//打印右子树
    }
}
 
/****************************************************************
*   函数名称：postOrderPrintTree() const
*   功能描述: 后序遍历打印该二叉树
*   参数列表: 无 
*   返回结果：void
*****************************************************************/
template<typename Comparable>
void BinarySearchTree<Comparable>::postOrderPrintTree() const
{
    cout << "后序遍历: ";
    postOrder(root); 
    cout << endl;
}
 
/****************************************************************
*   函数名称：postOrder(BinaryNode * t) const
*   功能描述: 后序遍历
*   参数列表: 当前结点的指针 
*   返回结果：void
*****************************************************************/
template<typename Comparable>
void BinarySearchTree<Comparable>::postOrder(BinaryNode * t) const
{
    if(t != NULL){
        postOrder(t->left);//打印左子树
        postOrder(t->right);//打印右子树
 
        for(int i = 0; i < t->num; ++i)
            cout << t->element << " ";//打印父结点，可能有多个值
 
    }
}
/****************************************************************
*   函数名称：insert(const Comparable & x) 
*   功能描述: 插入值为x的结点 
*   参数列表: x 要插入的值 
*   返回结果：void
*****************************************************************/
template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x)
{
    insert(x, root);
}
 
/****************************************************************
*   函数名称：insert(const Comparable & x, BinaryNode * & t) const
*   功能描述: 在结点t上插入值为x的结点 
*   参数列表: x 要插入的值 
*             t 要插入到结点t上
*   返回结果：void
*****************************************************************/
template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x, BinaryNode * & t) const
{
    if(t == NULL)
        t = new BinaryNode(x, NULL, NULL, 1);
    else if(x > t->element)
        insert(x, t->right);
    else if(x < t->element)
        insert(x, t->left);
    else if(x == t->element)//如果要插入的值和当前结点的值相同，则将当前结点的个数加1
        t->num++;
}
 
 
 
 
//test the functiona of remove
int main()
{
    BinarySearchTree<int> tree;
    tree.insert(8);
    tree.insert(6);
    tree.insert(10);
    tree.insert(5);
    tree.insert(7);
    tree.insert(9);
    tree.insert(11);
    tree.insert(12);
 
 
    cout << "树的深度 = " << tree.TreeDepth() << endl;

    cout << "按层遍历二叉树: ";
    tree.topToBottonPrintTree();
    tree.topToBottonPrintTree2();
 
    tree.preOrderPrintTree();
    tree.inOrderPrintTree();
    tree.postOrderPrintTree();

 
    return 0;
}
