/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月06日 星期三 22时06分45秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Tree
{
    public:

        Tree(){num = 0; p = NULL;}
        Tree(const Tree & t){num = t.num; p = t.p;}
        void get_num(){
            cout << "num = " << num << endl;
        }

        void get_p(){
            if(p == NULL)
                cout << "p == NULL" << endl;
            else
                cout << "p != NULL" << endl;
        }

    private:
        int num;
        char * p;
};

int main()
{
    int n;
    cout << "Test default constructor: " << endl;

    Tree tree;
    cout << "sizeof(tree) = " << sizeof(tree) << endl;
    tree.get_num();
    tree.get_p();
    Tree tree2 = tree;

    cout << "sizeof(tree) = " << sizeof(tree2) << endl;
    tree2.get_num();
    tree2.get_p();

    return 0;
}
