/*************************************************************************
	> File Name: binaryTreeBuild.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 19 Jun 2016 04:59:26 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

typedef int Type;

//树结点的数据结构
typedef struct BinaryTreeNode
{
    Type element;
    BinaryTreeNode * left;
    BinaryTreeNode * right;
}BinaryTreeNode;

BinaryTreeNode * construct(int * preStart, int * preEnd, int * inStart, int * inEnd)
{
    //创建根结点
    int rootValue = preStart[0];
    BinaryTreeNode * root = new BinaryTreeNode();
    root->element = rootValue;
    root->left = NULL;
    root->right = NULL;

    //如果此时只剩下了一个结点
    if(preStart==preEnd){
        if(inStart==inEnd && *preStart==*inStart)
            return root;
    }


    //在中序序列中找到根结点的位置
    int * rootInorder = inStart;
    while(rootInorder <= inEnd && rootValue != *rootInorder)
        ++rootInorder;


    int length = rootInorder - inStart;
    int * preLeftEnd = preStart + length;

    if(length>0){
        root->left = construct(preStart+1, preLeftEnd, inStart, rootInorder-1);
    }

    if(length < inEnd-inStart){
        root->right = construct(preLeftEnd+1, preEnd, rootInorder+1, inEnd);
    }

    return root;
}

//构造二叉树
BinaryTreeNode * binaryTreeBuild(int * preArr, int * inArr, int length)
{
    if(preArr==NULL || inArr==NULL || length<=0)
        return NULL;

    return construct(preArr, preArr+length-1, inArr, inArr+length-1);
}

//前序遍历二叉树
void preorderPrint(BinaryTreeNode * root)
{
    if(root != NULL){
        cout << root->element << " ";
        preorderPrint(root->left);
        preorderPrint(root->right);
    }
}

//中序遍历二叉树
void inorderPrint(BinaryTreeNode * root)
{
    if(root != NULL){
        inorderPrint(root->left);
        cout << root->element << " ";
        inorderPrint(root->right);
    }
}

//后序遍历二叉树
void postorderPrint(BinaryTreeNode * root)
{
    if(root != NULL){
        postorderPrint(root->left);
        postorderPrint(root->right);
        cout << root->element << " ";
    }
}

//主函数用于测试
int main()
{
    int preArr[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inArr[] = {4, 7, 2, 1, 5, 3, 8, 6};

    BinaryTreeNode * tree = binaryTreeBuild(preArr, inArr, sizeof(preArr)/sizeof(int));
    if(tree == NULL)
        return -1;

    cout << "前序遍历: ";
    preorderPrint(tree);
    cout << endl;

    cout << "中序遍历: ";
    inorderPrint(tree);
    cout << endl;

    cout << "后序遍历: ";
    postorderPrint(tree);
    cout << endl;

    return 0;
}
