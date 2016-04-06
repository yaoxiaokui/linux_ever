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
using namespace std;


template<typename Comparable>
class BinarySearchTree{
    public:
        BinarySearchTree(){root = NULL;}
        BinarySearchTree(const BinarySearchTree & rhs);
        ~BinarySearchTree();
        
        const Comparable & findMin() const;//查找最小值
        const Comparable & findMax() const;//查找最大值
        bool contains(const Comparable & x) const;//判断该二叉查找树是否包含值为x的结点
        bool isEmpty() const;//判断该二叉查找树是否为空 
        void printTree() const;//打印该二叉查找树

        void makeEmpty();//清空该二叉查找树
        void insert(const Comparable & x);//插入结点
        void remove(const Comparable & x);//移除结点值为x的结点

        const BinarySearchTree & operator=(const BinarySearchTree & rhs);//赋值运算符重载
    private:
        struct BinaryNode{
            Comparable element;
            BinaryNode * left;
            BinaryNode * right;

            BinaryNode(const Comparable & e, BinaryNode* lt, BinaryNode* rt):element(e), left(lt), right(rt){}
        };

        BinaryNode* root;

        void insert(const Comparable & x, BinaryNode * &t) const;
        void printTree(BinaryNode * t) const;
};

//析构函数
template<typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
    
}
//按从小到大的顺序打印该二叉树
template<typename Comparable>
void BinarySearchTree<Comparable>::printTree() const
{
    cout << "按从小到大的顺序输出该二叉查找树: " << endl;
    printTree(root); 
    cout << endl;
}

template<typename Comparable>
void BinarySearchTree<Comparable>::printTree(BinaryNode * t) const
{
    if(t != NULL){
        printTree(t->left);
        cout << t->element << " ";
        printTree(t->right);
    }
}
//移除结点
template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable & x)
{
    
}


template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x)
{
    insert(x, root);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x, BinaryNode * & t) const
{
    if(t == NULL)
        t = new BinaryNode(x, NULL, NULL);
    else if(x > t->element)
        insert(x, t->right);
    else if(x < t->element);
        insert(x, t->left);
}




int main()
{

    srand(unsigned (time(0)));

    vector<int> v;

    for(int i = 0; i < 10; ++i)
        v.push_back(rand()%10); 

    cout << "随机产生的数据序列: ";
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;

    BinarySearchTree<int> tree;

    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        tree.insert(*it); 
    
    tree.printTree();

    return 0;
}
