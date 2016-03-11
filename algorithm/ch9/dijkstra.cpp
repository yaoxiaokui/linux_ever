/*************************************************************************
	> File Name: Topological_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月23日 星期二 22时16分30秒
 ************************************************************************/

#include <iostream>
#include <list>
#include <queue>
#include <climits>

using namespace std;

struct unweighted_table{
    bool known;
    int distance;
    int path;
};

struct Type{
    int vertex;
    bool known;
    int distance;
    int path;
};

class Graph{
    private:
        int vertex_num;//图顶点个数
        list<Type> * adjlist;//邻接表，要生成vertex_num个
    public:
        Graph(int v);//类构造函数
        ~Graph();//类析构函数
        void addEdge(int v1, int v2, int value);
        void printGraph();
        void unweighted(int sv);
        void dijkstra(int sv);
};

Graph::Graph(int v)
{
    vertex_num = v;
    adjlist = new list<Type>[v+1];
    for(int i = 1; i <= v; ++i){
        Type ver;
        ver.vertex = i;
        ver.known = false;
        ver.distance = INT_MAX;
        ver.path = INT_MAX;

        adjlist[i].push_back(ver);
    }
}

Graph::~Graph()
{
    delete [] adjlist;
}

void Graph::dijkstra(int sv)
{
    adjlist[sv].front().distance;

    int min_val = INT_MAX;
    int min_vertex;

    for( ; ; ){
        min_val = INT_MAX;

        for(int i = 1; i <= vertex_num; ++i){//找到距离v最小的点,找不到则退出
            if(min_val > table[i].distance && !table[i].known){
                min_val = table[i].distance;
                min_vertex = i;
            }
        }
        if(min_val == INT_MAX)//没有找到合适的点，以及找完了，则退出循环
            break;

        table[min_vertex].known = true;

        for(list<Type>::iterator it = adjlist[min_vertex].begin(); it != adjlist[min_vertex].end(); ++it){
            int tmp = (*it).vertex;
            if(!table[tmp].known){
                if(table[tmp].distance > table[min_vertex].distance + adjlist[min_vertex])
            }
    }
    
}
void Graph::unweighted(int sv)
{
    struct unweighted_table * table = new unweighted_table[vertex_num+1];//从1开始

    //表信息初始化
    for(int i = 1; i <= vertex_num; ++i){
        table[i].distance = INT_MAX;
    }

    queue<int> que;
    table[sv].distance = 0;
    que.push(sv);

    if(adjlist[sv].empty()){//该顶点不能到其它任何顶点
        cout << "顶点" << sv << "不能到任何点" << endl;
        delete [] table;
        return;
    }

    while(!que.empty()){
        int v = que.front();
        que.pop();

        for(list<Type>::iterator it = adjlist[v].begin(); it != adjlist[v].end(); ++it){
            if(table[(*it).vertex].distance == INT_MAX){
                table[(*it).vertex].distance = table[v].distance+1;
                table[(*it).vertex].path = v;
                que.push((*it).vertex);
            }
        }
    }
    
    //下面是输出顶点到其它点的最小距离和与它相邻的顶点
    cout << "输出顶点" << sv << "到其它点的最小距离信息" << endl;
    cout << "-------------------" << endl;
    cout << "v\td\tp" << endl;
    cout << "-------------------" << endl;
    for(int i = 1; i <= vertex_num; ++i){
        cout << i << "\t" << table[i].distance << "\t" << table[i].path << endl;
    }
    cout << "-------------------" << endl;

    delete [] table;
}

void Graph::printGraph()
{
    cout << "-----------------------------------------" << endl;
    for(int i = 1; i <= vertex_num; ++i){
        cout << i << " ---> ";
        //for(list<int>::iterator it = adjlist[i].begin(); it != adjlist[i].end(); ++it){
        for(list<Type>::iterator it = adjlist[i].begin(); it != adjlist[i].end(); ++it){
            cout << (*it).vertex << " ---> ";
        }
        cout << " NULL " << endl;
    }
    cout << "-----------------------------------------" << endl;
}

void Graph::addEdge(int v1, int v2, int value)
{
    Type ver;
    ver.vertex = v2;
    ver.known = false;
    ver.distance = value;
    ver.path = INT_MAX;

    adjlist[v1].push_back(ver);

}


int main()
{
    Graph G(7);
    G.addEdge(1, 2, 2);
    G.addEdge(1, 4, 1);
    G.addEdge(2, 4, 3);
    G.addEdge(2, 5, 10);
    G.addEdge(3, 1, 4);
    G.addEdge(3, 6, 5);
    G.addEdge(4, 3, 2);
    G.addEdge(4, 5, 2);
    G.addEdge(4, 6, 8);
    G.addEdge(4, 7, 4);
    G.addEdge(5, 7, 6);
    G.addEdge(7, 6, 1);

    cout << "图的邻接表输出为: " << endl;
    G.printGraph();
   
    G.unweighted(1);
    G.unweighted(3);//求顶点3到其它顶点的最小距离
    G.unweighted(6);//求顶点6到其它顶点的最小距离


    return 0;
}
