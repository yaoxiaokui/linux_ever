/*************************************************************************
	> File Name: hashTable.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月12日 星期二 10时35分14秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


/****************************************************************
*   数据类名称：Employee
*   内容描述: 作为散列表的数据项目
*****************************************************************/

class Employee{
    public:
        Employee(){name=""; salary=0.0; seniority=0;};
        Employee(const string & n, double sal, int sen):name(n), salary(sal), seniority(sen){}
        //获得该类的name成员
        const string & getName() const
        { return name; }

        //重载==运算符 
        bool operator==(const Employee & rhs) const
        { return getName() == rhs.getName(); }

        //重载!=运算符 
        bool operator!=(const Employee & rhs) const
        { return !(*this == rhs); }

        friend ostream & operator<<(const ostream & os, const Employee & e){
            cout << "name: " << e.name << ",\tsalary: " << e.salary << ",\tseniority: " << e.seniority << endl;
        }
    private:
        string name;
        double salary;
        int seniority;
};

/****************************************************************
*   函数名称：hash(const HashedObj & key)
*   功能描述: 根据键值求个hash值,这个函数是根据一个特定的数学公式 
*   参数列表: key 数据项的键值 
*   返回结果：返回一个通过散列函数求得的值
*****************************************************************/
int hash(const string & key)
{
    int hashVal = 0;

    //用散列函数的那个公式求和
    for(int i = 0; i < key.length(); ++i)
        hashVal = 37*hashVal + key[i];

    return hashVal;
}

/****************************************************************
*   函数名称：hash(const HashedObj & key)
*   功能描述: 根据键值求个hash值,这个函数是根据一个特定的数学公式 
*   参数列表: key 数据项的键值 
*   返回结果：返回一个通过散列函数求得的值
*****************************************************************/
int hash(const Employee & item)
{
    return hash(item.getName());
}


/****************************************************************
*   散列表类名称：HashTable
*   内容描述: 散列表类
*****************************************************************/
template<typename HashedObj>
class HashTable{
    public:
        explicit HashTable(int size = 11):theLists(size), currentSize(0){}
        ~HashTable();

        bool containes(const HashedObj & x) const;//判断是否包含数据项x
        void makeEmpty();//清空散列表
        bool isEmpty();
        bool insert(const HashedObj & x);//插入项x
        bool remove(const HashedObj & x);//删除项x

        void print();//输出散列表中的内容
        HashedObj findElement(const HashedObj & x);//根据名字查找数据项


    private:
        vector<list<HashedObj> > theLists;//散列表的结构,theLists大小默认初始化为11
        int currentSize;//散列表中当前存放的元素个数
    private:
        void rehash();//再散列
        int myhash(const HashedObj & x) const;//散列函数
        int nextPrime(int n);//求的距离N最近的一个素数
};

/****************************************************************
*   函数名称：findElement(const HashedObj & x) const
*   功能描述: 查找元素x 
*   参数列表: x是要查找的元素
*   返回结果：如果找到则返回该元素，否则返回一个默认构造的元素值
*****************************************************************/
template<typename HashedObj>
HashedObj HashTable<HashedObj>::findElement(const HashedObj & x)
{
    list<HashedObj> & whichList = theLists[myhash(x)];
    
    typename list<HashedObj>::iterator it = find(whichList.begin(), whichList.end(), x);
    if(it != whichList.end())
        return *it;
    else{
        HashedObj obj;//返回一个成员值为0的对象
        return obj;
    }
}


/****************************************************************
*   函数名称：print()
*   功能描述: 输出散列表中的内容
*   参数列表: 无 
*   返回结果：无
*****************************************************************/
template<typename HashedObj>
void HashTable<HashedObj>::print()
{
    cout << "输出散列表中的内容: " << endl;
    for(unsigned i = 0; i < theLists.size(); ++i){
        cout << i << ": " << endl;
        for(typename list<HashedObj>::iterator it = theLists[i].begin(); it != theLists[i].end(); ++it){
            cout << *it; 
        }
    }
}

/****************************************************************
*   函数名称：isEmpty()
*   功能描述: 判断散列表是否为空
*   参数列表: 无 
*   返回结果：无
*****************************************************************/
template<typename HashedObj>
bool HashTable<HashedObj>::isEmpty()
{
    return currentSize == 0;
}

/****************************************************************
*   函数名称：makeEmpty()
*   功能描述: 清空散列表 
*   参数列表: 无 
*   返回结果：无
*****************************************************************/
template<typename HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
    for(int i = 0; i < theLists.size(); ++i)
        theLists[i].clear();

    currentSize = 0;//当前元素个数设为0
}

/****************************************************************
*   函数名称：containes(const HashedObj & x) const
*   功能描述: 判断散列表是否包含值为x的元素 
*   参数列表: x数据项
*   返回结果：如果包括x则返回true,否则返回false
*****************************************************************/
template<typename HashedObj>
bool HashTable<HashedObj>::containes(const HashedObj & x) const
{
    const list<HashedObj> & whichList = theLists[myhash(x)];
    return find(whichList.begin(), whichList.end(), x) != whichList.end();
}


/****************************************************************
*   函数名称：containes(const HashedObj & x) const
*   功能描述: 判断散列表是否包含值为x的元素 
*   参数列表: x数据项
*   返回结果：如果包括x则返回true,否则返回false
*****************************************************************/
template<typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj & x)
{
    list<HashedObj> & whichList = theLists[myhash(x)];

    typename list<HashedObj>::iterator it = find(whichList.begin(), whichList.end(), x);

    if(it == whichList.end())
        return false;

    whichList.erase(it);//删除元素x
    --currentSize;
    return true;
}

/****************************************************************
*   函数名称：insert(const HashedObj & x)
*   功能描述: 在散列表中插入元素x,如果插入项已经存在，则什么都不做。
*             否则将其放在表的前端
*   参数列表: x数据项
*   返回结果：插入成功返回true, 否则返回false
*****************************************************************/
template<typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj & x)
{
    list<HashedObj> & whichList = theLists[myhash(x)];
    
    if(find(whichList.begin(), whichList.end(), x) != whichList.end())
        return false;

    whichList.push_back(x);

    //rehash
    if(++currentSize > theLists.size())
        rehash();//扩充表的大小

    return true;

}


/****************************************************************
*   函数名称：~HashTable()
*   功能描述: 析构函数
*   参数列表: 无
*   返回结果：无
*****************************************************************/
template<typename HashedObj>
HashTable<HashedObj>::~HashTable()
{
    
}

/****************************************************************
*   函数名称：nextPrime(int n)
*   功能描述: 获得距离n最近的一个素数 
*   参数列表: n表示数值 
*   返回结果：返回一个素数 
*****************************************************************/
template<typename HashedObj>
int HashTable<HashedObj>::nextPrime(int n)
{
    int i;

    if(n % 2 == 0)
        n++;

    for(; ; n += 2){
        for(i = 3; i*i <= n; i += 2)
            if(n % i == 0)
                goto ContOuter;
        return n;
        ContOuter: ;
    }
}
/****************************************************************
*   函数名称：rehash()
*   功能描述: 扩大散列表的大小
*   参数列表: 无
*   返回结果：无 
*****************************************************************/
template<typename HashedObj>
void HashTable<HashedObj>::rehash()
{
    vector<list<HashedObj> > oldLists = theLists;
    
    //创建一个新的大小为原来两倍大小的散列表
    theLists.resize(nextPrime(2 * theLists.size()));

    for(int i = 0; i < theLists.size(); ++i)
        theLists[i].clear();

    //复制散列表
    for(int i = 0; i < oldLists.size(); ++i){
        typename  list<HashedObj>::iterator it = oldLists[i].begin();
        while(it != oldLists[i].end())
            insert(*it++);
    }
}

/****************************************************************
*   函数名称：myhash(const HashedObj & key)
*   功能描述: 根据键值求个hash值 
*   参数列表: key 数据项的键值 
*   返回结果：返回hash值
*****************************************************************/
template<typename HashedObj>
int HashTable<HashedObj>::myhash(const HashedObj & key) const
{
    int hashVal = hash(key);
    
    hashVal %= theLists.size();

    if(hashVal < 0)
        hashVal += theLists.size();

    return hashVal;
}




int main()
{
    Employee e1("linux", 101.00, 1);
    Employee e2("ever", 102.00, 2);
    Employee e3("peter", 103.00, 3);
    Employee e4("may", 104.00, 4);
    Employee e5("usa", 105.00, 5);
    Employee e6("sal", 106.00, 6);
    Employee e7("usa", 107.00, 7);//和上面的值重复，所以这个值会被忽略
    Employee e8("jan", 108.00, 8);
    Employee e9("kro", 109.00, 9);
    Employee e10("bei", 110.00, 10);
    
    Employee e12("bbb", 110.00, 10);

    vector<Employee> v;
    v.push_back(e1);
    v.push_back(e2);
    v.push_back(e3);
    v.push_back(e4);
    v.push_back(e5);
    v.push_back(e6);
    v.push_back(e7);
    v.push_back(e8);
    v.push_back(e9);
    v.push_back(e10);

    cout << "v: " << endl;
    for(unsigned i = 0; i < v.size(); ++i)
        cout << v[i];
    cout << endl;

    HashTable<Employee> hashTable;
    
    for(unsigned i = 0; i < v.size(); ++i)
        hashTable.insert(v[i]);

    hashTable.print();

    cout << endl;
    //测试查找函数findElement
    cout << "测试查找函数findElement: " << endl;
    Employee e11 = hashTable.findElement(e12);
    cout << "e11 = " << e11;
    Employee e13 = hashTable.findElement(e10);
    cout << "e13 = " << e13;
    cout << endl;

    cout << "测试包含函数containes: " << endl; 
    if(hashTable.containes(e10))
        cout << "containe e10" << endl;
    else 
        cout << "not containe e10" << endl;

    if(hashTable.containes(e11))
        cout << "containe e11" << endl;
    else 
        cout << "not containe e11" << endl;
        
    cout << "测试remove()：" << endl;
    hashTable.remove(e10);
    if(hashTable.containes(e10))
        cout << "containe e10" << endl;
    else 
        cout << "not containe e10" << endl;
    cout << endl;

    cout << "测试isEmpty(): " << endl;
    if(hashTable.isEmpty())
        cout << "hashTable is Empty " << endl;
    else
        cout << "hashTable is not Empty " << endl;
    cout << endl;

    cout << "测试makeEmpty(): " << endl;
    hashTable.makeEmpty();
    if(hashTable.isEmpty())
        cout << "hashTable is Empty " << endl << endl;
    else
        cout << "hashTable is not Empty " << endl;
    cout << endl;


    return 0;
}
