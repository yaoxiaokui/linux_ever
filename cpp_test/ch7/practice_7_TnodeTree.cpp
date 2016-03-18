/*************************************************************************
	> File Name: practice_7_TnodeTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月18日 星期五 10时56分28秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

typedef struct Tnode{
    string word;
    int count;//该单词的个数
    Tnode * left;
    Tnode * right;
}Tnode;

class Tree{
    private:
        Tnode * root;

    public:
        Tree(){ root = NULL; }
        Tree(Tnode * pNode):root(pNode){}
        void addNode(string word);
        void printTree();
        int isEmpty();
    private:
        Tnode * newNode(const string & word);
        void addNode(Tnode* pnode, const string & word);
        void rightMove(Tnode* pcurrent, Tnode* pinsertNode);
        void leftMove(Tnode* pcurrent, Tnode* pinsertNode);
        void printTree(Tnode * pnode);
};

Tnode * Tree::newNode(const string & word)
{
    Tnode * pnode = new Tnode;
    pnode->word = word;
    pnode->count = 1;
    pnode->left = NULL;
    pnode->right = NULL;

    return pnode;
}

/*
1:如果当前节点的左孩子为空,则当前节点的左孩子设为pinsertNode
2:如果当前节点的值大于左孩子,则调用左子树向下移动rightMove(pcurrent->left, pinsertNode);
3:如果当前节点的值小于左孩子,则调用左子树向下移动leftMove(pcurrent->left, pinsertNode);
*/
void Tree::leftMove(Tnode* pcurrent, Tnode* pinsertNode)
{
    if(pcurrent->left == NULL)
        pcurrent->left = pinsertNode;
    else if(pinsertNode->word > pcurrent->left->word)
        rightMove(pcurrent->left, pinsertNode);
    else if(pinsertNode->word < pcurrent->left->word)
        leftMove(pcurrent->left, pinsertNode);
}

/*
1:如果当前节点的右孩子为空,则当前节点的右孩子设为pinsertNode
2:如果当前节点的值大于右孩子，则调用右子树向下移动rightMove(pcurrent->right, pinsertNode)
3:如果当前节点的值小于右孩子，则调用右子树向下移动leftMove(pcurrent->right, pinsertNode)
*/
void Tree::rightMove(Tnode* pcurrent, Tnode* pinsertNode)
{
    if(pcurrent->right == NULL){
        pcurrent->right = pinsertNode;
    }
    else if(pinsertNode->word > pcurrent->right->word)
        leftMove(pcurrent->right, pinsertNode);
    else if(pinsertNode->word < pcurrent->right->word)
        rightMove(pcurrent->right, pinsertNode);
}

/*
1: 当前节点的值等于word,则当前节点的count加1

2：word大于当前节点的值，并且word大于当前节点的右节点,则将word插入到当前节点的右节点
   word大于当前节点的值，并且word小于当前节点的右节点，则将word插入到当前节点，并将当前节点的值向左子树移动

3: word小于当前节点的值，并且word小于当前节点的左节点，则将word插入到当前节点的左子树
   word小于当前节点的值，并且word大于当前节点的左节点，则将word插入到当前节点，并将当前节点的值向右子树移动
*/

void Tree::addNode(Tnode* pnode, const string & word)
{
    if(word == pnode->word){//当前节点的word等于word，只需要将个数加1
        pnode->count++;
    }
    else if(word > pnode->word){//当前节点的word小于word，则将word插入到当前节点的右子树
        if(pnode->right == NULL){
            Tnode * pnew = newNode(word); //新的节点
            pnode->right = pnew;
        }
        else if(word >= pnode->right->word){
            addNode(pnode->right, word);
        }
        else if(word < pnode->right->word){
            //将word插入到当前节点，当前节点的值右移
            Tnode * temp = newNode(word);
            temp->word = pnode->word;
            temp->count = pnode->count;
            
            pnode->word = word; 
            pnode->count = 1;

            leftMove(pnode->right, temp);//之前的顶点
        }
    }
    else if(word < pnode->word){//word大于左子树的word，但是小于右子树的值
        if(pnode->left == NULL){
            Tnode * pnew = newNode(word);
            pnode->left = pnew;
        }
        else if(word <= pnode->left->word){
            addNode(pnode->left, word);
        }
        else if(word > pnode->left->word){
            Tnode * temp = newNode(word);
            temp->word = pnode->word;
            temp->count = pnode->count;

            pnode->word = word;
            pnode->count = 1;

            rightMove(pnode->left, temp);
        }

    }
}

void Tree::addNode(string word)
{
    if(isEmpty()){//树为空树
        root = newNode(word); //新的节点
    }
    else{//树为非空
        addNode(root, word);
    }
}

void Tree::printTree()
{
    printTree(root);
}

void Tree::printTree(Tnode * pnode)
{
    if(pnode == NULL){
        return;
    }    
    else{//中序遍历输出
        printTree(pnode->left);
        cout << pnode->word << "(" << pnode->count << "), ";
        printTree(pnode->right);
    }
}

int Tree::isEmpty()
{
    return (root == NULL) ? 1:0;
}


//Tree的接口：printTree(), addNode(word),isEmpty();
#define WORD_NUM 5

int main()
{
    Tree tree;
    string word;

    //输入单词
    for(int i = 0; i < WORD_NUM; ++i){
        cout << "输入单词:";
        cin >> word;
        tree.addNode(word);
    }

    tree.printTree();
    cout << endl;
    
    return 0;
}
