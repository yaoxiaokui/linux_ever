/*************************************************************************
	> File Name: ant_search.h
	> Author: 
	> Mail: 
	> Created Time: 2016年03月21日 星期一 12时47分17秒
 ************************************************************************/

#ifndef _ANT_SEARCH_H
#define _ANT_SEARCH_H

#include "graph.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using std::set_intersection;


#define TIME 1000
#define ANT_NUMBER 1000 

class Ant{

    private:
        vector<int> m_passed_path;//蚂蚁经过的路径
        int m_passed_len;//蚂蚁走过的长度
        int m_cur_ver;//当前所在的顶点
        int m_next_ver;//下一步到达的顶点
        int m_cur_path_len;//当前要经过的路径的长度

        int cost;

        int src;//起点
        int dest;//目的点
        vector<int> vertex_subset;
    public:
        Ant();
        ~Ant(){}
        int move(int num);//移动到下一步,路程加1或者  移动到了目的点然后选择下一个目的点
        void add_ver(int ver);
        void next_ver(int num, int curr_cer);//根据当前顶点选择下一个顶点
        void update_dest_len();
        void search();
        void get_demand_value(char*demand);
        void init();
        void print_result();
        int get_cost();
        int include_vertex_subset();
        int get_m_cur_ver();
};

int Ant::get_m_cur_ver()
{
    return m_cur_ver;
}

int Ant::get_cost()
{
    return cost;
}
void Ant::print_result()
{
    for(unsigned int i = 0; i < m_passed_path.size(); ++i)
        cout << m_passed_path[i] << "--->";
    cout << endl;
}

void Ant::init()
{
    add_ver(src);
    m_cur_ver = src;
}

int Ant::include_vertex_subset()
{
    vector<int> output(vertex_subset.size());
    sort(m_passed_path.begin(), m_passed_path.end());

    set_intersection(m_passed_path.begin(), m_passed_path.end(), vertex_subset.begin(), vertex_subset.end(), output.begin());

    for(unsigned int i = 0; i < vertex_subset.size(); ++i){
        if(vertex_subset[i] != output[i])
            return 0;
    }
    
    return 1;
}
/*
1：判断蚂蚁走过的长度加1, m_passed_len++;
2：判断蚂蚁走过的长度是否和要经过的长度是否一样。 m_passed_len ==? m_cur_path_len;
    如果一样则表示到达了该点，然后判断该点是否是dest，
                              dest如果是则将m_cur_ver更新为dest
                              如果该点不是dest，则调用next_ver选择下一个点


    如果不一样的表示没有达到该点，则退出
*/
int Ant::move(int num)
{

    if((m_cur_ver == src) && (m_cur_path_len == 0))
        next_ver(num, m_cur_ver);

    if(m_cur_ver == dest)
        return 1;

//    cout << "m_passed_len = " << m_passed_len << ", m_cur_path_len = " << m_cur_path_len << endl;
    m_passed_len++;

    if(m_passed_len == m_cur_path_len){

        m_cur_ver = m_next_ver;
        add_ver(m_cur_ver);

        //if((include_vertex_subset()) && (m_cur_ver == dest)){
        if(m_cur_ver == dest){
            for(unsigned int i = 0; i < m_passed_path.size(); ++i)
                cout << m_passed_path[i] << "--->";
            cout << ", cost = " << cost << endl;
            return 1;

        }

        next_ver(num, m_cur_ver);   
    }

    return 0;
}



void Ant::next_ver(int num, int curr_cer)
{
    srand(num*num);
    int val = rand()%graph_list[curr_cer].size();
    
 //   cout << "val = " << val << endl;
    m_passed_len = 0;
    m_next_ver = graph_list[curr_cer][val].vertex; 
    m_cur_path_len = graph_list[curr_cer][val].weight;

    
    cost += m_cur_path_len;
    //return graph_list[curr_cer][val].vertex; 
}

void Ant::add_ver(int ver)
{
   m_passed_path.push_back(ver); 
}


Ant::Ant()
{
    m_passed_len = 0;
    m_cur_ver = -1;    
    m_next_ver = -1;
    m_cur_path_len = 0;
    cost = 0;
}


/*************************************************
函数名称：get_demand_value
参数列表:
函数功能：获得起点和终点，以及必须经过的点的集合
返回值：无
*************************************************/
void Ant::get_demand_value(char* demand)
{
    char buff[20];
    unsigned int i = 0, j = 0, val;
    vector<int> v;
    memset(buff, 0, 20);

    while((demand[i] != '\n') && (demand[i] != '\0')){
        if((demand[i] != ',') && (demand[i] != '|')){
            buff[j] = demand[i];
            j++;
        }
        else{
            j = 0;
            val = atoi(buff); 
            v.push_back(val);
            //cout << "val = " << val << endl;
            memset(buff, 0, 20);
        }
        i++;
    }
    val = atoi(buff); 
    v.push_back(val);
    //cout << "val = " << val << endl;

    src = v[0];//源点
    dest = v[1];//目的点
    //获得必须经过的图的部分顶点
    for(i = 2; i < v.size(); ++i){
        vertex_subset.push_back(v[i]);  
    }
    sort(vertex_subset.begin(), vertex_subset.end());//从小到大排序
}
    

#endif
