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
            cout << "name: " << e.name << ",\tsalary: " << e.salary << ",\tseniority: " << e.seniority;
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
        explicit HashTable(int size = 11):array(nextPrime(size)), currentSize(0){makeEmpty();}
        ~HashTable();

        bool containes(const HashedObj & x);//判断是否包含数据项x
        void makeEmpty();//清空散列表
        bool isEmpty();
        bool insert(const HashedObj & x);//插入项x
        bool remove(const HashedObj & x);//删除项x

        void print();//输出散列表中的内容
        int findPos(const HashedObj & x);//根据名字查找数据项
        HashedObj findElement(const HashedObj & x);//根据名字查找数据项,并返回

        enum EntryType {ACTIVE, EMPTY, DELETED};//每个数据单元都有一个info变量，表明该位置是否被占用、空或已删除
        
    private:
        //散列表的数据单元结构
        struct HashEntry{
            HashedObj element;//该散列表存放的数据
            EntryType info;//表明该位置的状态 

            HashEntry(const HashedObj & e = HashedObj(), EntryType i = EMPTY):element(e), info(i){}
        };

        vector<HashEntry> array;//散列表
        int currentSize;//散列表中当前存放的元素个数
    private:
        void rehash();//再散列
        int myhash(const HashedObj & x) const;//散列函数
        int nextPrime(int n);//求的距离N最近的一个大于N的素数
        int prePrime(int n);//求距离N最近的一个小于N的素数
        bool isActive(int currentPos) const;//判断位置currentPos处的是否有元素

    public:
        friend ostream & operator<<(const ostream & os, const HashEntry & e){
            cout << "element: " << e.element << ", info = " << e.info;
        }
};


/****************************************************************
*   函数名称：findElement(const HashedObj & x) const
*   功能描述: 查找x的位置
*   参数列表: x是要查找的元素
*   返回结果：如果找到则返回该元素的引用
*****************************************************************/
template<typename HashedObj>
HashedObj HashTable<HashedObj>::findElement(const HashedObj & x)
{
    int currentPos = findPos(x);

    if(isActive(currentPos))//找了则返回
        return array[currentPos].element;
    else{//没有找到,返回一个空值
        HashedObj obj;
        return obj;
    }
}


/****************************************************************
*   函数名称：findPos(const HashedObj & x) const
*   功能描述: 查找x应该插入的位置
*   参数列表: x是要插入的元素
*   返回结果：如果找到空的位置则返回要插入的位置标号
*****************************************************************/
template<typename HashedObj>
int HashTable<HashedObj>::findPos(const HashedObj & x)
{
    //线性探测f(i) = i; f(i) = f(i-1) + 1;相隔为1
    //平方探测f(i) = i*i; f(i) = f(i-1) + 2*i - 1; 相隔为2*i-1
    //双散列，f(i) = i*hash2(x); f(i) = f(i-1)+hash2(x);相隔为hash2(x);
    //hash2(x) = R-(x%R); R=prePrime(array.size()),R为小于TableSize()的素数
    int offset = 1;

    int currentPos = myhash(x);

    //如果找到了空的位置则返回位置标号
    //如果找到了该元素x，则返回该元素的位置标号
    while(array[currentPos].info != EMPTY && array[currentPos].element != x){
         //currentPos += offset;//线性探测
         currentPos += 2 * offset -1;//平方探测
         //currentPos += prePrime(array.size()) - myhash(x)%prePrime(array.size());//双散列
         offset++;

        if(currentPos >= array.size())
            currentPos -= array.size();
    }
    
    return currentPos;
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
    for(unsigned i = 0; i < array.size(); ++i){
        if(isActive(i))
            cout << i << ": " << endl << array[i] << endl;
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
    for(int i = 0; i < array.size(); ++i)
        array[i].info = EMPTY;

    currentSize = 0;//当前元素个数设为0
}

/****************************************************************
*   函数名称：containes(const HashedObj & x) const
*   功能描述: 判断散列表是否包含值为x的元素 
*   参数列表: x数据项
*   返回结果：如果包括x则返回true,否则返回false
*****************************************************************/
template<typename HashedObj>
bool HashTable<HashedObj>::containes(const HashedObj & x)
{
    //findPos(x)返回的位置是ACTIVE的说明存在该元素x
    return isActive(findPos(x));
}

/****************************************************************
*   函数名称：isActive(int currentPos) const
*   功能描述: 判断位置currentPos处的是否有元素 
*   参数列表: currentPos是散列表currentPos处的位置 
*   返回结果：如果currentPos处有元素则返回true,否则返回false
*****************************************************************/
template<typename HashedObj>
bool HashTable<HashedObj>::isActive(int currentPos) const
{
    return array[currentPos].info == ACTIVE;
}

/****************************************************************
*   函数名称：remove(const HashedObj & x)
*   功能描述: 删除散列表中的值为x的元素 
*   参数列表: x数据项
*   返回结果：成功删除返回true,否则返回false
*****************************************************************/
template<typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj & x)
{
    int currentPos = findPos(x);
    if(!isActive(currentPos))
        return false;

    array[currentPos].info = DELETED;//懒惰删除，仅仅将标识位info设置为Deleted

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
    int currentPos = findPos(x);//先找到位置
    if(isActive(currentPos))//如果该位置处已经存放了该元素，则之间返回false
        return false;

    array[currentPos] = HashEntry(x, ACTIVE);

    //如果当前散列表中元素的个数大于散列表长度的一半，则扩大散列表为原来的2倍
    if(++currentSize > array.size()/2)
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
*   函数名称：prePrime(int n)
*   功能描述: 获得距离n最近的一个小于n的素数 
*   参数列表: n表示数值 
*   返回结果：返回一个素数 
*****************************************************************/
template<typename HashedObj>
int HashTable<HashedObj>::prePrime(int n)
{
    int i;

    if(n % 2 == 0)
        n--;

    for(; ; n -= 2){
        for(i = 3; i*i <= n; i += 2){
            if(n % i == 0)
                goto ContOuter;
        }
        return n;

        ContOuter: ;
    }
}

/****************************************************************
*   函数名称：nextPrime(int n)
*   功能描述: 获得距离n最近的一个大于n的素数 
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
    
    vector<HashEntry> oldArray = array;

    //创建一个新的大小为原来两倍大小的散列表
    array.resize(nextPrime(2 * oldArray.size()));

    for(int i = 0; i < array.size(); ++i)
        array[i].info = EMPTY;

    currentSize = 0;
    //复制散列表
    for(int i = 0; i < oldArray.size(); ++i){
        if(oldArray[i].info == ACTIVE)
            insert(oldArray[i].element);
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
    
    hashVal %= array.size();

    if(hashVal < 0)
        hashVal += array.size();

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
        cout << v[i] << endl;
    cout << endl;

    HashTable<Employee> hashTable;
    
    for(unsigned i = 0; i < v.size(); ++i)
        hashTable.insert(v[i]);

    hashTable.print();

    cout << endl;

    cout << "测试包含函数containes: " << endl; 
    if(hashTable.containes(e10))
        cout << "containe e10" << endl;
    else 
        cout << "not containe e10" << endl;

    if(hashTable.containes(e12))
        cout << "containe e12" << endl;
    else 
        cout << "not containe e12" << endl;
        
    cout << "\n测试findElement(): " << endl;
    
    Employee e11 = hashTable.findElement(e8);
    cout << "e11: " << e11 << endl;
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



    return 0;
}
