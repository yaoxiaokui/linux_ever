#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iterator>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

using namespace std;

#define MAX_VERTEX_NUM 600

//保存每个顶点信息的数据结构
struct GraphNode{
    int vertex;//当前顶点的标号
    int inDegree;//当前顶点的入度
    int topNum;//当前顶点的拓扑排序的顺序标号
};

//图节点信息
typedef struct Node{ 
    int edge_num;//边号 
    int src;//源点 
    int vertex;//自身 
    int weight;//边的权重 
}Node; 

/*******************************************************
*  类名称： 邻接表图
********************************************************/ 
class Graph{
    private:
        int edge_num;//图边的个数
        int vertex_num;//图的顶点数目
        list<Node> * graph_list;//邻接表
        vector<GraphNode> nodeArr;//保存每个顶点信息的数组
        
    public:
        Graph(){}
        Graph(char* graph[], int edgenum); 
        ~Graph();
        void print();
        vector<int> topoSort();//拓扑排序
    private:
        vector<int> get_graph_value(char* graph[], int columns);
        void addEdge(char* graph[], int columns);
};


/*************************************************
*  函数名称：topoSort()
*  功能描述：对图中的顶点进行拓扑排序
*  参数列表：无
*  返回结果：返回顶点拓扑排序之后的结果
*************************************************/
vector<int> Graph::topoSort()
{
    vector<int> topoSortArr;

    for(int count = 0; count < vertex_num; ++count){
        //找到一个入度为0的顶点
        int i;
        for(i = 0; i < vertex_num; ++i){
            if((nodeArr[i].inDegree == 0)&&(nodeArr[i].vertex != -1))
                break;
        }

        if(i == vertex_num)
            break;

        //此时顶点i的入度为0
        //删除该点和删除与该点相邻的边
        //并将与顶点i相连的顶点的入度减1
        nodeArr[i].inDegree = -1;
        for(list<Node>::iterator it = graph_list[i].begin(); it != graph_list[i].end(); ++it){
            nodeArr[(*it).vertex].inDegree--;
        }

        topoSortArr.push_back(i);
    }

    return topoSortArr;
}

/*************************************************
*  函数名称：print
*  功能描述：将图的信息以邻接表的形式输出到标准输出
*  参数列表：无
*  返回结果：无
*************************************************/
void Graph::print()
{
    cout << "******************************************************************" << endl; 
    //for(int i = 0 ; i < MAX_VERTEX_NUM; ++i){
    for(int i = 0 ; i < vertex_num; ++i){
        if(graph_list[i].begin() != graph_list[i].end()){
            cout << i << "-->";
            for(list<Node>::iterator it = graph_list[i].begin(); it != graph_list[i].end(); ++it){
                cout << (*it).vertex << "(边号:" << (*it).edge_num << ",权重:" << (*it).weight << ")-->";
            }
            cout << "NULL" << endl;
        }
    }

    cout << "******************************************************************" << endl; 
}

/*************************************************
*  函数名称：get_graph_value
*  功能描述：将图的每一条边的信息保存到一个数组中
*  参数列表: graph：指向图信息的二维数组
             columns:图的第几条边
*  返回结果：无
*************************************************/
vector<int> Graph::get_graph_value(char* graph[], int columns)
{
    vector<int> v;
    char buff[20];
    int i = 0, j = 0, val;
    memset(buff, 0, 20);

    while((graph[columns][i] != '\n') && (graph[columns][i] != '\0')){
        if(graph[columns][i] != ','){
            buff[j] = graph[columns][i];
            j++;
        }
        else{
            j = 0;
            val = atoi(buff); 
            v.push_back(val);
            memset(buff, 0, 20);
        }
        i++;
    }
    val = atoi(buff); 
    v.push_back(val);

    return v;
}



/*************************************************
*  函数名称：addEdge
*  功能描述：将图的每一条边的信息加入图的邻接表中
*  参数列表：graph：指向图信息的二维数组
             columns:图的第几条边
*  返回结果：无
*************************************************/
void Graph::addEdge(char* graph[], int columns)
{
    Node node;
    vector<int> v = get_graph_value(graph, columns);

    node.edge_num = v[0];
    node.src = v[1];
    node.vertex = v[2];
    node.weight = v[3];


    //根据顶点的标号，求的总的顶点数目
    if(node.vertex > vertex_num)
        vertex_num = node.vertex;

    //要考虑重复的边，但是边的权重不一样
    for(list<Node>::iterator it = graph_list[node.src].begin(); it != graph_list[node.src].end(); ++it){
        if((*it).vertex == node.vertex){
            if((*it).weight > node.weight){
                (*it).weight = node.weight;   
            }
            return;
        }
    }

    //将信息写入到保存每个顶点的数组中
    nodeArr[node.src].vertex = node.src;
    nodeArr[node.vertex].vertex = node.vertex;
    nodeArr[node.vertex].inDegree++;//入度加1 

    graph_list[node.src].push_back(node);
}


/*************************************************
*  函数名称：构造函数
*  功能描述：以邻接表的形式保存图的信息,并保存必须经过的顶点
*  参数列表：graph：指向图信息的二维数组
             edgenum:图的边的个数
*  返回结果：无
*************************************************/
Graph::Graph(char* graph[], int edgenum):nodeArr(MAX_VERTEX_NUM)
{
    edge_num =  edgenum; 
    vertex_num = 0;
    graph_list = new list<Node>[MAX_VERTEX_NUM+1];

    //对保存顶点信息的数组进行初始化，如果vertext=-1表示没有该顶点
    for(int i = 0; i < MAX_VERTEX_NUM; ++i){
        nodeArr[i].vertex = -1;
        nodeArr[i].inDegree = 0;
        nodeArr[i].topNum = -1;
    }

    for(int i = 0; i < edgenum; ++i){
        addEdge(graph, i);   
    }

    vertex_num++;
}


/*************************************************
*  函数名称：析构函数
*  功能描述：释放动态分配的内存
*  参数列表：无
*  返回结果：无
*************************************************/
Graph::~Graph()
{
    delete[] graph_list;
}

#endif
