/*************************************************************************
	> File Name: BinaryTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月06日 星期三 10时24分29秒
 ************************************************************************/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define Type char

struct Node
{
    Type element;
    struct Node * left;
    struct Node * right;
};

class BinaryTree{
    public:
        BinaryTree(struct Node * r = NULL):root(r){}
        BinaryTree(vector<Type> & v);
        ~BinaryTree();
        void inOrderPrint();
    private:
        void deleteNode(struct Node * pNode);
        void init(vector<Type> & v);
        void inOrderPrint(struct Node *node);
    private:
        stack<struct Node*> st;
        struct Node * root;
};


//中序输出该表达式树
void BinaryTree::inOrderPrint()
{
    cout << "中序输出该表达式树: ";
    inOrderPrint(root); 
    cout << endl;
}
void BinaryTree::inOrderPrint(struct Node* node)
{
    if(node != NULL){
        inOrderPrint(node->left);
        cout << node->element << " ";
        inOrderPrint(node->right);
    } 
}

//构造函数
BinaryTree::BinaryTree(vector<Type> &v)
{
    init(v);
}
//析构函数
BinaryTree::~BinaryTree()
{
    deleteNode(root); 
}

//释放树结点内存空间
void BinaryTree::deleteNode(struct Node * pNode)
{
    if(pNode != NULL){
        delete pNode;
        deleteNode(pNode->left);
        deleteNode(pNode->right);
    }
}

//初始化树，将后缀输出转换为表达式
void BinaryTree::init(vector<Type> &v)
{
    for(unsigned i = 0; i < v.size(); ++i){
        struct Node * pNode = new Node;
        pNode->element = v[i];
        pNode->left = NULL;
        pNode->right = NULL;

        if((v[i] == '+') || (v[i] == '-') || (v[i] == '*') || (v[i] == '/') || (v[i] == '%')){
            pNode->right = st.top();
            st.pop();
            pNode->left = st.top();
            st.pop();
        }

        st.push(pNode);
    }

    root = st.top();
}


int main()
{
    vector<Type> v;
    Type tmp;

    cout << "输出表达式的后缀输出形式: ";
    while(cin >> tmp){
        v.push_back(tmp);
    }

    BinaryTree tree(v);
    tree.inOrderPrint();//中序输出


    return 0;
}
