/*************************************************************************
	> File Name: list.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 19 Jun 2016 02:41:47 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <stack>
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


//输出链表的所有数据
void print(Node * root)
{
    cout << "顺序输出: ";
    Node * current = root;
    while(current != NULL){
        cout << current->element << " ";
        current = current->next;
    }
    cout << endl;
    
}


void reversePrint(Node **proot)
{
    cout << "倒序输出: ";
    stack<Node *> listNodes;

    if(proot == NULL || *proot == NULL)
        return;

    Node * current = *proot;
    while(current != NULL){
        listNodes.push(current);
        current = current->next;
    }

    while(!listNodes.empty()){
        current = listNodes.top();
        cout << current->element << " ";
        listNodes.pop();
    }
    cout << endl;

}
//主函数
int main()
{
    Node * root;//链表的根指针
    
    insert(&root, 3);
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 5);
    insert(&root, 4);
    insert(&root, 8);
    insert(&root, 9);

    print(root);

    reversePrint(&root);

    return 0;
}
