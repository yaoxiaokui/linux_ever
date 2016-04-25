/*************************************************************************
	> File Name: DisjointSets.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月25日 星期一 11时22分48秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;


/********************************************
*    类名称：不相交集合类DisjSets
********************************************/
class DisjSets{
    public:
        explicit DisjSets(int numElements);
        ~DisjSets(){}
        
        int find(int x) const;//查找
        void unionSets(int root1, int root2);//合并
        void unionSetsBySize(int root1, int root2);//按树大小合并
        void unionSetsByHeight(int root1, int root2);//按树高度合并
        void print();
    private:
        void print(int x);
    private:
        vector<int> s;//存放每个元素的根节点或父节点
};


/****************************************************************
*   函数名称：DisjSets(int numElements)
*   功能描述: 构造函数,同时对每个元素进行集合初始化
*   参数列表: numElements是集合中元素的个数
*   返回结果：无
*****************************************************************/
DisjSets::DisjSets(int numElements):s(numElements)
{
    for(unsigned i = 0; i < s.size(); ++i)
        s[i] = -1;
}

/****************************************************************
*   函数名称：print(int x)
*   功能描述: 打印元素x
*   参数列表: x是元素的
*   返回结果：void 
*****************************************************************/
void DisjSets::print(int x)
{
    cout << x << " "; 
    for(unsigned i = 0; i < s.size(); ++i){
        if(s[i] == x)
            print(i);
    }
}
/****************************************************************
*   函数名称：print
*   功能描述: 打印集合中的元素
*   参数列表: 无
*   返回结果：void 
*****************************************************************/
void DisjSets::print()
{
    cout << "输出不相交集合类(每行表示一个相交集合): " << endl;
    cout << "s: ";
    for(unsigned i = 0; i < s.size(); ++i)
        cout << s[i] << " ";
    cout << endl;

    for(unsigned i = 0; i < s.size(); ++i){
        if(s[i] < 0){
            print(i);
            cout << endl;
        }
    }
}

/****************************************************************
*   函数名称：find(int x) const
*   功能描述: 查找元素x处于集合的名字
*   参数列表: x是要查找的元素
*   返回结果：返回元素x的集合名字
*****************************************************************/
int DisjSets::find(int x) const
{
    if(s[x] < 0)
        return x;
    else
        return find(s[x]);
}


/****************************************************************
*   函数名称：unionSets(int root1, int root2)
*   功能描述: 合并两个集合
*   参数列表: root1表示集合1，root2表示集合2
*   返回结果：void 
*****************************************************************/
void DisjSets::unionSets(int root1, int root2)
{
    s[root2] = root1; 
}

/****************************************************************
*   函数名称：unionSetsBySize(int root1, int root2)
*   功能描述: 按集合大小合并两个集合,使得较小的树成为较大树的子树
*   参数列表: root1表示集合1，root2表示集合2
*   返回结果：void 
*****************************************************************/
void DisjSets::unionSetsBySize(int root1, int root2)
{
    if(s[root2] < s[root1]){//root2树比较大
        s[root2] += s[root1];//更新树的大小
        s[root1] = root2;//root1的父节点变为root2
    }
    else{
        s[root1] += s[root2];
        s[root2] = root1;
    }
}


/****************************************************************
*   函数名称：unionSetsByHeight(int root1, int root2)
*   功能描述: 按集合高度合并两个集合,使较浅的树成为较深的树的子树
*   参数列表: root1表示集合1，root2表示集合2
*   返回结果：void 
*****************************************************************/
void DisjSets::unionSetsByHeight(int root1, int root2)
{
    if(s[root2] < s[root1]){//root2树比较高
        s[root1] = root2;//直接合并， root1成为root2树的子树 
    }
    else{//root1树比较高，或相等。

         //如果相等则更新树的高度
        if(s[root1] == s[root2])
            s[root1]--;
         s[root2] = root1;
    }
    
}


//测试主函数
int main()
{
    cout << "任意合并: " << endl;
    DisjSets disjSets(8);
    disjSets.unionSets(4, 5);
    disjSets.unionSets(6, 7);
    disjSets.unionSets(4, 6);

    disjSets.print();

    cout << "按大小合并: " << endl;
    DisjSets disjSets2(8);
    disjSets2.unionSetsBySize(4, 5);
    disjSets2.unionSetsBySize(6, 7);
    disjSets2.unionSetsBySize(4, 6);
    disjSets2.unionSetsBySize(3, 4);
    disjSets2.print();


    cout << "按高度合并: " << endl;
    DisjSets disjSets3(8);
    disjSets3.unionSetsByHeight(4, 5);
    disjSets3.unionSetsByHeight(6, 7);
    disjSets3.unionSetsByHeight(4, 6);
    disjSets3.unionSetsByHeight(3, 4);
    disjSets3.print();

    return 0;
}
