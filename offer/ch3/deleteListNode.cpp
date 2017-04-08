/*************************************************************************
	> File Name: list.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 19 Jun 2016 02:41:47 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;


//链表结点的数据结构
typedef struct Node
{
    int element;
    Node * next;
}Node;

//在链表的末尾插入数据value
void insert(Node ** proot , int value)
{
    Node *current = *proot;

    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->element = value;
    newNode->next = NULL;

    if(*proot == NULL){//空链表
        *proot = newNode;
    }
    else{
        while(current->next != NULL)
            current = current->next;

        current->next = newNode;
    }
}

//删除deleteNode指向的结点，并且在O(1)时间完成删除
void deleteNode(Node **proot, Node * deleteNode)
{
    if(*proot == NULL || deleteNode == NULL || proot == NULL)
        return;

    //如果删除的顶点不是尾结点
    if(deleteNode->next != NULL){

        Node * deleteNodeNextNode = deleteNode->next;
        *deleteNode = *deleteNodeNextNode;
        deleteNode->next = deleteNodeNextNode->next;

        delete deleteNodeNextNode;
        deleteNodeNextNode = NULL;
    }
    else if(*proot == deleteNode){//头部结点
        delete deleteNode;
        deleteNode = NULL;
        *proot = NULL;
    }
    else{//尾结点
        Node * current = *proot;
        while(current->next != deleteNode){
            current = current->next;
        }

        current->next = NULL;
        delete deleteNode;
        deleteNode = NULL;
    }
}

//删除链表中元素值为value的结点
void remove(Node **proot, int value)
{
    if(*proot== NULL || proot == NULL)
        return;
    
    Node * current = *proot;
    Node * previous = NULL;

    while(current->element != value){
        previous = current;
        current = current->next;
    }

    //current此时指向要删除的结点,并且不是第一个不是第一个节点
    if(current != *proot)
        previous->next = current->next;
    else
        *proot = current->next;

    free(current);
}

//查找结点元素值为element的结点 
Node * find(Node * root, int element)
{
    Node * current = root;
    while(current != NULL){
        if(current->element == element)
            break;
        else
            current = current->next;
    }

    return current;
}

//输出链表的所有数据
void print(Node * root)
{
    Node * current = root;
    while(current != NULL){
        cout << current->element << " ";
        current = current->next;
    }
    cout << endl;
    
}

//主函数
int main()
{
    Node * root = NULL;//链表的根指针
    
    print(root);

    insert(&root, 3);
    insert(&root, 1);

    Node * find3 = find(root, 3);
    if(find3!= NULL)
        cout << "find3->element = " << find3->element << endl;
    else
        cout << "not find 3" << endl;

    deleteNode(&root, find3);

    print(root);

    insert(&root, 2);
    insert(&root, 5);
    insert(&root, 4);
    insert(&root, 8);
    insert(&root, 9);


    print(root);

    //remove(&root, 3);
    print(root);

    remove(&root, 5);
    print(root);

    remove(&root, 9);
    print(root);


    return 0;
}
