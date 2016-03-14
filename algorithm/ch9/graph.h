typedef struct Vertex{ 
    int dist;// 
    int path; 
    bool know; 
}Vertex; 
vector<Vertex> vertexs(MAX_VERTEX_NUM); 


/*表示图的类*/
class Graph{
    private:
        int vertex_num;//暂时没使用到该信息 
        int edge_num;
        list<Node> * graph_list;
    public:
        Graph(){}
        ~Graph();
        int dijkstra(int s, int d);
};

int Graph::dijkstra(int s, int d)
{
    for(int i = 0; i < vertex_num; ++i){//对所有顶点信息初始化
        vertexs[i].dist = MAX_VALUE;
        vertexs[i].path = -1;
        vertexs[i].know = false;
    }

    //将与src点相邻的点的权重初始化
    for(list<Node>::iterator it = graph_list[s].begin(); it != graph_list[s].end(); ++it){
        vertexs[(*it).vertex].dist = (*it).weight;
    }
    vertexs[s].dist = 0;

    int v = -1;

    for(int i = 0; i < vertex_num; ++i){
        v = -1;
        int min_val = MAX_VALUE;
        for(int j = 0; j < vertex_num; ++j){
            if((vertexs[j].know == false) && (vertexs[j].dist < min_val) && (!vertexs[j].used)){
                min_val = vertexs[j].dist;
                v = j;//v是dist值最小的点。并且是unknow
            }
        }    

        vertexs[v].know = true;

        //对于每一个和v相邻的节点w，如果w是未知的，并且 v.dist + dist(v, w) < w.dist
        //则w.dist = v.dist + dist(v, w);并且w.know = true;
        for(list<Node>::iterator it = graph_list[v].begin(); it != graph_list[v].end(); ++it){
            if(!vertexs[(*it).vertex].know){
                if(vertexs[v].dist + (*it).weight < vertexs[(*it).vertex].dist){
                    vertexs[(*it).vertex].dist = vertexs[v].dist + (*it).weight;
                    vertexs[(*it).vertex].path = v;
                }
            }
        }
    }

    return vertexs[d].dist; //返回的是 s到d的最短距离
}

