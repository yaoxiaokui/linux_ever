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
    int distance;
    int path;
};

class Graph{
    private:
        int vertex_num;//图顶点个数
        list<int> * adjlist;//邻接表，要生成vertex_num个
    public:
        Graph(int v);//类构造函数
        ~Graph();//类析构函数
        void addEdge(int v1, int v2);
        void printGraph();
        void unweighted(int sv);
};

Graph::Graph(int v)
{
    vertex_num = v;
    adjlist = new list<int>[v+1];
}

Graph::~Graph()
{
    delete [] adjlist;
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

        for(list<int>::iterator it = adjlist[v].begin(); it != adjlist[v].end(); ++it){
            if(table[*it].distance == INT_MAX){
                table[*it].distance = table[v].distance+1;
                table[*it].path = v;
                que.push(*it);
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
        for(list<int>::iterator it = adjlist[i].begin(); it != adjlist[i].end(); ++it){
            cout << *it << " ---> ";
        }
        cout << " NULL " << endl;
    }
    cout << "-----------------------------------------" << endl;
}

void Graph::addEdge(int v1, int v2)
{
    adjlist[v1].push_back(v2);
}


int main()
{
    Graph G(7);
    G.addEdge(1, 2);
    G.addEdge(1, 4);
    G.addEdge(2, 4);
    G.addEdge(2, 5);
    G.addEdge(3, 1);
    G.addEdge(3, 6);
    G.addEdge(4, 3);
    G.addEdge(4, 6);
    G.addEdge(4, 7);
    G.addEdge(4, 5);
    G.addEdge(5, 7);
    G.addEdge(7, 6);

    cout << "图的邻接表输出为: " << endl;
    G.printGraph();
   

    G.unweighted(3);//求顶点3到其它顶点的最小距离
    G.unweighted(6);//求顶点6到其它顶点的最小距离


    return 0;
}
