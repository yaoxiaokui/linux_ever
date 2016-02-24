/*************************************************************************
	> File Name: Topological_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月23日 星期二 22时16分30秒
 ************************************************************************/

#include <iostream>
#include <list>
#include <queue>
using namespace std;


class Graph{
    private:
        int vertex_num;//图顶点个数
        list<int> * adjlist;//邻接表，要生成vertex_num个
        int * indegree;//保存vertex_num个顶点的rudu，初始值为0
    public:
        Graph(int v);//类构造函数
        ~Graph();//类析构函数
        void addEdge(int v1, int v2);
        bool topologicalSort();
        void printGraph();
};

Graph::Graph(int v)
{
    vertex_num = v;
    adjlist = new list<int>[v];
    
    indegree = new int[v];
    for(int i = 0; i < v; ++i)//将顶点的入度初始值置为0
    {
        indegree[i] = 0;
    }
}

Graph::~Graph()
{
    delete [] adjlist;
    delete [] indegree;
}

void Graph::printGraph()
{
    for(int i = 0; i < vertex_num; ++i){
        cout << i << " ---> ";
        for(list<int>::iterator it = adjlist[i].begin(); it != adjlist[i].end(); ++it){
            cout << *it << " ---> ";
        }
        cout << " NULL " << endl;
    }
}

void Graph::addEdge(int v1, int v2)
{
    adjlist[v1].push_back(v2);
    ++indegree[v2];
}

bool Graph::topologicalSort()
{
    queue<int> que;//保存入度为0个顶点
   //将所有入度为0的顶点入队
    for(int i = 0; i < vertex_num; ++i){
        if(indegree[i] == 0)
            que.push(i);
    }

    int counter = 0;
    while(!que.empty()){
        int vertex = que.front();
        que.pop();
        cout << vertex << " ";

        counter++;
        for(list<int>::iterator it = adjlist[vertex].begin(); it != adjlist[vertex].end(); ++it){
            if(--indegree[*it] == 0){
                que.push(*it);    
            }
        }
    }
    cout << endl;

    return counter == vertex_num;
}

int main()
{
    Graph G(6);
    G.addEdge(5, 2);
    G.addEdge(5, 0);
    G.addEdge(4, 0);
    G.addEdge(4, 1);
    G.addEdge(2, 3);
    G.addEdge(3, 1);
    
    G.printGraph();
    if(G.topologicalSort())
        cout << "拓扑排序正确\n";
    else
        cout << "拓扑排序不正确\n";

    return 0;
}
