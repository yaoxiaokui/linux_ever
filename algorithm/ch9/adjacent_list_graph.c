/*************************************************************************
	> File Name: adjacent_list_graph.c
	> Author: 
	> Mail: 
	> Created Time: 2016年02月23日 星期二 19时32分11秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef int VertexType;

#define MaxVerNum 100 //最大顶点数目为100

//边表结点
typedef struct node{
    VertexType adjvex;//邻接点域
    //如果边有权值的话可以再加一个成员变量int info;
    struct node *next;//指向下一个邻接点域
}EdgeNode;

//顶点表结点
typedef struct vnode{
    VertexType vertex;//顶点域
    EdgeNode * firstdge;//边表头指针
}VertexNode;

typedef VertexNode AdjList[MaxVerNum];

typedef struct{
    AdjList adjlist;//邻接表
    int n;//顶点数
    int e;//边数
}ALGraph;//ALGraph是以邻接表方式存储的图类型 

//建立一个有向图的邻接表存储的算法
void CreateALGraph(ALGraph * G)
{
    int i, j, k;
    EdgeNode * e;

    printf("输入图的顶点数和边数(n, e): \n");
    scanf("%d, %d", &(G->n), &(G->e));
    //建立n个顶点的顶点表
    printf("输入顶点信息：\n");
    for(i = 0; i < G->n; ++i){
        scanf("%d", &(G->adjlist[i].vertex));//输入顶点信息
        G->adjlist[i].firstdge = NULL;//顶点的边表头指针为空
    }
    
    //建立边表
    printf("输入边的信息(i, j):\n");
    for(k = 0; k < G->e; ++k){
        scanf("%d, %d", &i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));//生成新的边表结点
        e->adjvex = j;
        e->next = G->adjlist[i].firstdge;
        G->adjlist[i].firstdge = e;
    }
}

int main()
{
    ALGraph G;
    CreateALGraph(&G);
    printf("Created the Graph.\n");

    return 0;
}
