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

//在链表的按从小到大的顺序插入数据value
void insert(Node ** proot , int value)
{
    if(proot == NULL)
        return;

    Node *current = *proot;
    Node * previous = NULL;

    while((current != NULL) && (value > current->element)){
        previous = current;
        current = current->next;
    }

    //生成新的结点
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->element = value;
    newNode->next = NULL;

    newNode->next = current;

    if(previous == NULL)
        *proot = newNode;
    else
        previous->next = newNode;

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


//找到链表的倒数第k个结点
Node * findKthToTail(Node * root, int k)
{
    //如果k的值小于等于0或者root为空指针，则直接返回
    if(k <= 0 || root == NULL)
        return NULL;

    Node * firsIndex = root;
    Node * nextIndex = root;

    //让指针nextIndex指向第k-1个结点
    for(unsigned int i = 0; i < k-1; ++i){
        nextIndex = nextIndex->next;

        //防止k的值大于链表的结点数目
        if(nextIndex == NULL)
            return NULL;
    }

    //然后两个指针同时向前走，直到nextIndex指向最后一个结点
    while(nextIndex->next != NULL){
        nextIndex = nextIndex->next;
        firsIndex = firsIndex->next;
    }

    return firsIndex;
}

//反转链表
void reverseList(Node **proot)
{
    if(proot == NULL || *proot == NULL)
        return;

    Node * previous = NULL;
    Node * current = NULL;

    current = *proot;

    while(current != NULL){
        
        //如果没有到达最后一个结点
        Node * next = current->next;//保存下一个结点的指针

        //如果current是最后一个结点
        if(next == NULL){
            *proot = current;//重新设置链表的根结点
        }

        current->next = previous;//让当前结点指向前面的结点
        previous = current;
        current = next;
    }
}


//合并两个排序链表,保持从小到大的顺序
Node * mergeOrderedList(Node * list1, Node * list2)
{
    if(list1 == NULL)
        return list2;
    else if(list2 == NULL)
        return list1;

    Node * newList = NULL;

    
    if(list1->element < list2->element){
        newList = list1;
        newList->next = mergeOrderedList(list1->next, list2);
    }
    else{
        newList = list2;
        newList->next = mergeOrderedList(list1, list2->next);
    }

    return newList;
}



//主函数
int main()
{
    Node * root = NULL;//链表的根指针
    
    insert(&root, 3);
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 5);

    cout << "list1: ";
    print(root);

    Node * root2 = NULL;

    insert(&root2, 4);
    insert(&root2, 8);
    insert(&root2, 6);
    insert(&root2, 7);
    insert(&root2, 9);

    cout << "list2: ";
    print(root2);


    Node * newList = mergeOrderedList(root, root2);
    cout << "newList: ";
    print(newList);


    return 0;
}
