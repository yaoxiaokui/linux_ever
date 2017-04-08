/*************************************************************************
	> File Name: mylist.c
	> Author: 
	> Mail: 
	> Created Time: Thu 16 Jun 2016 10:04:58 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;
typedef struct Node * PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

//链表的节点结构
struct Node{
    ElementType Element;
    Position Next;
};

//链表的操作
int IsEmpty(List L);
int IsLast(List L, Position p);
Position Find(List L, ElementType e);
Position FindPrevious(List L, ElementType e);
void Delete(List L, ElementType e);
void Insert(List L, Position p, ElementType e);
void PrintList(List L);

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position p, List L)
{
    return p->Next == NULL;
}

void Insert(List L, Position p, ElementType e)
{
    Position newNode = (Position)malloc(sizeof(struct Node));
    newNode->Element = e;

    if(L->Next == NULL){
        L->Next = newNode;
        newNode->Next = NULL;
    }

    if(p != NULL){
        newNode->Next = p->Next;
        p->Next = newNode;
    }

}

Position Find(List L, ElementType e)
{
    Position p = L->Next;

    while((p != NULL) && (p->Element == e))
        p = p->Next;

    return p;
}

Position FindPrevious(List L, ElementType e)
{
    Position p = L;

    while((p->Next != NULL) && (p->Next->Element != e))
        p = p->Next;

    return p;
}

void Delete(List L, ElementType e)
{
    Position p = FindPrevious(L, e);

    if(p->Next == NULL){
        printf("not find Element %d\n", e);
        return;
    }

    Position temp = p->Next;
    p->Next = p->Next->Next;

    free(temp);
}

void PrintList(List L)
{
    Position p = L->Next;

    while(p != NULL){
        printf("%d ", p->Element);
        p = p->Next;
    }

    printf("\n");
}


//测速主函数

int main()
{
    List list = (List)malloc(sizeof(struct Node));
    list->Next = NULL;

    Insert(list, NULL, 3);

    PrintList(list);


    return 0;
}
