/*************************************************************************
	> File Name: tree_print.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月05日 星期二 09时10分02秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define TYPE char

//树的节点
struct TreeNode{
    TYPE element;//该节点的元素
    TreeNode *firstChild;//指向该节点的第一个孩子
    TreeNode *nextSibling;//指向该节点的兄弟节点
    
};

class Tree{
    public:
        Tree(TreeNode * r = NULL):root(r){}
        Tree(int node_num);
        ~Tree();

        void addNode(int i, int j); 
        void preOrder();//前序遍历
        void print();//打印
    private:
        void print(TreeNode* node, int num);
        void addBrotherNode(TreeNode* bro, TreeNode* node);
        void preOrder(TreeNode* parent);//前序遍历
    private:
        TreeNode * root;//该树的根
};

//打印树的形状
void Tree::print()
{
    print(root, 0);
}

void printSpace(int num)
{
    int i = 0;
    for(i = 0; i < num-3; i++)
        cout << " ";

    for(; i < num-2; ++i)
        cout << "|";
    for(; i < num; ++i)
        cout << "_";
}


void Tree::print(TreeNode* node, int num)
{
    if(node != NULL){
        printSpace(num); 
        cout << node->element << endl;  
        print(node->firstChild, num+4);
        print(node->nextSibling, num);
    }
}

//前序遍历
void Tree::preOrder()
{
    cout << "前序遍历: ";
    preOrder(root);
    cout << endl;
}

void Tree::preOrder(TreeNode* parent)
{
    if(parent != NULL){
        cout << parent->element << " ";
        preOrder(parent->firstChild);
        preOrder(parent->nextSibling);
    }
}

//分配并初始化所有的树结点
Tree::Tree(int node_num)
{
    root = new TreeNode[node_num];

    char ch = 'A';

    for(int i = 0; i < node_num; ++i){
        root[i].element = ch + i;
        root[i].firstChild = NULL;
        root[i].nextSibling = NULL;
    }

}

//释放所有节点的内存空间
Tree::~Tree()
{
    if(root != NULL)
        delete [] root;
}

//addNode将父子结点组对
//如果父节点的firstChild==NULL, 则firstChild = node;
//如果父节点的firstChild != NULL, 则
void Tree::addNode(int i, int j)
{
    TreeNode* parent = &root[i];
    TreeNode* node = &root[j];

    if(parent->firstChild == NULL)
        parent->firstChild = node;
    else
        addBrotherNode(parent->firstChild, node);
}

//将节点插入到兄弟节点
void Tree::addBrotherNode(TreeNode* bro, TreeNode* node)
{
    if(bro->nextSibling == NULL)
        bro->nextSibling = node;
    else
        addBrotherNode(bro->nextSibling, node);
}

//主函数
int main()
{
    Tree tree(16);//分配十六个节点

    tree.addNode(0, 1);
    tree.addNode(0, 2);
    tree.addNode(0, 3);
    tree.addNode(0, 4);
    tree.addNode(0, 5);
    tree.addNode(0, 6);
    tree.addNode(3, 7);
    tree.addNode(4, 8);
    tree.addNode(4, 9);
    tree.addNode(5, 10);
    tree.addNode(5, 11);
    tree.addNode(5, 12);
    tree.addNode(6, 13);
    tree.addNode(9, 14);
    tree.addNode(9, 15);


    cout << "Tree1: " << endl;
    tree.preOrder();
    tree.print();
    

    Tree tree2(9);
    tree2.addNode(0, 1);
    tree2.addNode(0, 2);
    tree2.addNode(1, 3);
    tree2.addNode(1, 4);
    tree2.addNode(2, 5);
    tree2.addNode(3, 6);
    tree2.addNode(5, 7);
    tree2.addNode(5, 8);

    cout << "Tree2: " << endl;
    tree2.preOrder();
    tree2.print();

    return 0;
}
