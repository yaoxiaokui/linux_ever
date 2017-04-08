/*************************************************************************
	> File Name: bfs.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Jul 2016 11:14:56 AM CST
 ************************************************************************/

#include <iostream>
#include <list>
#include <queue>
using namespace std;


class Graph{
private:
    int num;//图中结点的数量
    list<int> * adj;//邻接表来表示图
public:
    Graph(int num){
        this->num = num;
        adj = new list<int>[num];
    }

    //添加v1-v2的边
    void addEdge(int v1, int v2){
        adj[v1].push_back(v2);
    }

    void BFS(int start);
        
};


void Graph::BFS(int start)
{
    //申请数组来标识每个结点是否被访问
    bool * visited = new bool[num];

    for(int i = 0; i < num; ++i)
        visited[i] = false;


    //添加起点，并标记起点已经被访问
    queue<int> que;
    que.push(start);
    visited[start] = true;

    while(!que.empty()){
        int node = que.front();
        que.pop();

        //输出该结点的值
        cout << node << " ";

        //依次遍历该结点的所有邻接点
        for(list<int>::iterator it = adj[node].begin(); it != adj[node].end(); ++it){

            //如果该结点没有访问，则标记该结点已经访问过
            //并将该结点的添加到队列里
            if(!visited[*it]){
                que.push(*it);
                visited[*it] = true;
            }
            
        }
    }

    cout << endl;

}

//主函数
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);


    g.BFS(2);

    return 0;
}

