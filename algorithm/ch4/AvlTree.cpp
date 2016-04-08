/*************************************************************************
	> File Name: AvlTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月08日 星期五 10时14分48秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


template<typename Comparable>
class AvlTree{
    public:
        AvlTree(){ root = NULL; }
        ~AvlTree();

        void makeEmpty();//清空该树
        bool isEmpty() const;//判断该树是否为空
        void lessOrderPrintTree();//从小到大输出该AVL平衡树
        void biggerOrderPrintTree();//从大到小输出该AVL平衡树
        void insert(const Comparable & x);//插入值为x的结点
        Comparable findMin() const;//找到最小值
        Comparable findMax() const;//找到最大值

    private:
        struct AvlNode{
            Comparable element;
            AvlNode * left;
            AvlNode * right;
            int height;
            AvlNode(const Comparable & e, AvlNode * lt, AvlNode * rt, int h = 0):element(e), left(lt), right(rt), height(h){}
        };
        AvlNode * root;

    private:
        void makeEmpty(AvlNode * t);
        void lessOrderPrintTree(AvlNode * t);
        void biggerOrderPrintTree(AvlNode * t);
        int height(AvlNode * t) const;//获得当前结点t的高度
        void insert(const Comparable & x, AvlNode * & t);//在t处，插入值为x的结点
        void rotateWithLeftChild(AvlNode * & k2);//单旋转，左左插入的情况
        void rotateWithRightChild(AvlNode * & k1);//单旋转，右右插入的情况
        void doubleWithLeftChild(AvlNode * & k3);//双旋转，左右插入的情况
        void doubleWithRightChild(AvlNode * & k1);//双旋转，右左插入的情况
        Comparable findMin(AvlNode * t) const;//找到最小值
        Comparable findMax(AvlNode * t) const;//找到最大值
};


/****************************************************************
*   函数名称：findMax() 
*   功能描述: 找到该树的最大值 
*   参数列表: 无 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
Comparable AvlTree<Comparable>::findMax() const
{
    if(!isEmpty())
        return findMax(root); 
}

/****************************************************************
*   函数名称：findMax(AvlNode * t) 
*   功能描述: 找到该树的最大值 
*   参数列表: t表示当前结点 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
Comparable AvlTree<Comparable>::findMax(AvlNode * t) const
{
    if(t->right== NULL)
        return t->element; 
    else 
        return findMax(t->right);

}

/****************************************************************
*   函数名称：findMin() 
*   功能描述: 找到该树的最小值 
*   参数列表: 无 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
Comparable AvlTree<Comparable>::findMin() const
{
    if(!isEmpty())
        return findMin(root); 
}

/****************************************************************
*   函数名称：findMin(AvlNode * t) 
*   功能描述: 找到该树的最小值 
*   参数列表: t表示当前结点 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
Comparable AvlTree<Comparable>::findMin(AvlNode * t) const
{
    if(t->left == NULL)
        return t->element; 
    else 
        return findMin(t->left);

}
/****************************************************************
*   函数名称：~AvlTree()
*   功能描述: 析构函数，释放结点内存空间 
*   参数列表: 无 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
AvlTree<Comparable>::~AvlTree()
{
    makeEmpty();
}
/****************************************************************
*   函数名称：void insert(const Comparable & x)
*   功能描述: 插入值为x的结点 
*   参数列表: x为要插入结点的值 
*   返回结果：void 
*****************************************************************/
template<typename Comparable>
void AvlTree<Comparable>::insert(const Comparable & x)
{
    insert(x, root);
}

/****************************************************************
*   函数名称：void insert(const Comparable & x, AvlNode * t)
*   功能描述: 在结点t的后面插入值为x的结点 
*   参数列表: x为要插入结点的值 
*             t为当前的结点
*   返回结果：void 
*****************************************************************/
template<typename Comparable>
void AvlTree<Comparable>::insert(const Comparable & x, AvlNode * & t)
{
    if(t == NULL)//当前结点为空
        t = new AvlNode(x, NULL, NULL);
    else if(x < t->element){
        insert(x, t->left);
        if(height(t->left) - height(t->right) == 2){
            if(x < t->left->element)//单旋转，左左插入
                rotateWithLeftChild(t);
            else
                doubleWithLeftChild(t);//双旋转，左右插入
        } 
    }
    else if(x > t->element){
        insert(x, t->right);
        if(height(t->right) - height(t->left) == 2){
            if(x > t->right->element)//单旋转，右右插入
                rotateWithRightChild(t);
            else
                doubleWithRightChild(t);//双旋转，右左插入
        }
    }
    //如果x的值和当前结点的值相同，则忽略。也可以向之前二叉查找树一样给每个结点再加一个num成员变量。
    t->height = max(height(t->left), height(t->right)) + 1;//更新结点t的高度
}

/****************************************************************
*   函数名称：rotateWithLeftChild(AvlNode *t)
*   功能描述: 将当前结点进行单旋转，用于左左插入的时候 
*   参数列表: t是指向当前结点的指针 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
void AvlTree<Comparable>::rotateWithLeftChild(AvlNode * & k2)
{
    cout << "左单旋转" << endl;
    AvlNode * k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;

    k2 = k1;
}
/****************************************************************
*   函数名称：rotateWithRightChild(AvlNode *t)
*   功能描述: 将当前结点进行单旋转，用于左右插入的时候 
*   参数列表: t是指向当前结点的指针 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
void AvlTree<Comparable>::rotateWithRightChild(AvlNode * & k1)
{
    cout << "右单旋转" << endl;
    AvlNode * k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;

    k1 = k2; 
}

/****************************************************************
*   函数名称：doubleWithLeftChild(AvlNode *t)
*   功能描述: 将当前结点进行双旋转，用于左右插入的时候 
*   参数列表: t是指向当前结点的指针 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
void AvlTree<Comparable>::doubleWithLeftChild(AvlNode * & k3)
{
    cout << "**********************" << endl;
    cout << "左双旋转: " << endl;
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
    cout << "**********************" << endl;
}

/****************************************************************
*   函数名称：doubleWithRightChild(AvlNode *t)
*   功能描述: 将当前结点进行双旋转，用于右左插入的时候 
*   参数列表: t是指向当前结点的指针 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
void AvlTree<Comparable>::doubleWithRightChild(AvlNode * & k1)
{
    cout << "**********************" << endl;
    cout << "右双旋转: " << endl;
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
    cout << "**********************" << endl;
}


/****************************************************************
*   函数名称：int height(AvlNode *t) const
*   功能描述: 获得当前结点t的高度 
*   参数列表: t是指向当前结点的指针 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
int AvlTree<Comparable>::height(AvlNode * t) const
{
    return (t == NULL) ? -1 : t->height;
}


/****************************************************************
*   函数名称：biggerOrderPrintTree()
*   功能描述: 按照从大到小的顺序输出该树结点
*   参数列表: 无 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
void AvlTree<Comparable>::biggerOrderPrintTree()
{
    cout << "从大到小输出：";
    biggerOrderPrintTree(root); 
    cout << endl;
}
/****************************************************************
*   函数名称：biggerOrderPrintTree(AvlNode * t)
*   功能描述: 按照从大到小的顺序输出该树结点
*   参数列表: 无 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
void AvlTree<Comparable>::biggerOrderPrintTree(AvlNode * t)
{
    if(t != NULL){
        biggerOrderPrintTree(t->right);
        cout << t->element << " ";
        biggerOrderPrintTree(t->left);
    } 
}

/****************************************************************
*   函数名称：lessOrderPrintTree()
*   功能描述: 按照从小到大的顺序输出该树结点
*   参数列表: 无 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
void AvlTree<Comparable>::lessOrderPrintTree()
{
    cout << "从小到大输出：";
    lessOrderPrintTree(root);    
    cout << endl;
}

/****************************************************************
*   函数名称：lessOrderPrintTree()
*   功能描述: 按照从小到大的顺序输出该树结点
*   参数列表: 无 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
void AvlTree<Comparable>::lessOrderPrintTree(AvlNode * t)
{
    if(t != NULL){
        lessOrderPrintTree(t->left);
        cout << t->element << " ";
        lessOrderPrintTree(t->right);
    }
}

/****************************************************************
*   函数名称：makeEmpty()
*   功能描述: 将该AVL平衡树清空
*   参数列表: 无 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
void AvlTree<Comparable>::makeEmpty()
{
   makeEmpty(root); 
}

/****************************************************************
*   函数名称：makeEmpty(struct AvlNode * t)
*   功能描述: 释放t指针指向的结点 
*   参数列表: t 当前结点的指针 
*   返回结果：无
*****************************************************************/
template<typename Comparable>
void AvlTree<Comparable>::makeEmpty(AvlNode * t)
{
    if(t != NULL){
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
}

/****************************************************************
*   函数名称：isEmpty()
*   功能描述: 判断该树是否为空 
*   参数列表: 无 
*   返回结果：如果为空则返回true;否则返回false;
*****************************************************************/
template<typename Comparable>
bool AvlTree<Comparable>::isEmpty() const
{
    return (root == NULL) ? true : false;
}


//测试主函数
int main()
{
    vector<int> v;
    AvlTree<int> tree;

    for(int i = 0; i < 10; i++)
        v.push_back(rand() % 10);

    cout << "v: ";
    for(int i = 0; i < 10; ++i)
        cout << v[i] << " ";
    cout << endl;

    cout << "构造AVL树trre1: " << endl;

    for(int i = 0; i < 10; ++i)
        tree.insert(v[i]);
    tree.insert(13);
    tree.insert(12);
    tree.insert(11);

    tree.lessOrderPrintTree();        
    tree.biggerOrderPrintTree();


    AvlTree<int> tree2;
    
    cout << "构造AVL树trre2: " << endl;
    for(int i = 1; i < 8; ++i)
        tree2.insert(i);
    tree2.insert(16);
    tree2.insert(15);

    tree2.lessOrderPrintTree();
    tree2.biggerOrderPrintTree();

    int min = tree2.findMin();
    cout << "min = " << min << endl;
    int max = tree2.findMax();
    cout << "max = " << max << endl;

    return 0;
}
