#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int intertuptCount(int cacheNum, vector<int> & v)
{
    //标记某个页是否已经缓存
    int book[201];
    for(int i = 1; i <= 200; ++i){
        book[i] = 0;
    }
    
    deque<int> que;
    if(cacheNum >= v.size() || v.size() <= 0)
        return 0;
    
    int count = 0;//缺页中断的统计次数
    
     
    for(int i = 0; i < v.size(); ++i){
        //如果已经缓存，则下一步
        //如果没有缓存，则再判断
        if(book[v[i]] == 0)
        {
            //没有缓存，此时没有满
            if(que.size() < cacheNum){
                que.push_back(v[i]);
                book[v[i]] = 1;
            }
            else if(que.size() >= cacheNum){
                //此时缓存已经满了
                count++;
                book[que.front()] = 0;
                que.pop_front();
                que.push_back(v[i]);
                book[v[i]] = 1;
            }
        }      
        
        
    } 
    
    
    return count;
}

int main()
{
    int cacheNum = 0;
    int m = 0;
    
    while(cin >> cacheNum >> m){
        //cin >> m;
        int value;
        vector<int> v;
        
        for(int i = 0; i < m; ++i){
            cin >> value;
            v.push_back(value);
        }
        
        cout << "num = " << intertuptCount(cacheNum, v) << endl;
    }
    
    
    return 0;
}
