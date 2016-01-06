/*************************************************************************
	> File Name: 224.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月14日 星期一 21时38分27秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void input_data(int * number, int * r, vector<int>  & x, vector<int> &book)
{
    cout << "输入点的个数：";
    cin >> *number;
    cout << "输入半径的大小: ";
    cin >> *r;
    cout << "输入每个点的位置: ";
    int i = 0;
    int val;

    while(i != *number){
        cin >> val;
        x.push_back(val);
        book.push_back(0);
        cin.get();
        i++;
    }
}


void output_data(int * number, int *r, vector<int> & x, vector<int> &book)
{
    cout << "N = " << *number << endl;
    cout << "r = " << *r << endl;
    cout << "X = ";
    for (vector<int>::iterator pos = x.begin(); pos != x.end(); ++pos){
        cout << *pos << " ";
    }
    cout << endl;
    for (vector<int>::iterator pos = book.begin(); pos != book.end(); ++pos){
        cout << *pos << " ";
    }
    cout << endl;
}

void solve(int * number, int * r, vector<int> & x, vector<int> & book)
{
    int i = 0;
    while(i < x.size()){
        if(i == 0){
            if(x[i+1] - x[i] > *r){
                book[i] = 1;
            }
        }
        else if(i < *number-1){
            if(book[i-1] == 0 && x[i+1]-x[i-1] > *r){
                book[i] = 1;
            }
        }
        else if (i == *number-1 && x[i]-x[i-1] > *r){
            book[i] = 1;
        }
        i++;
    }

    cout << "the result is :";
    for (i = 0; i < book.size(); ++i){
        if (book[i] == 1)
            cout << x[i] << " ";
    }
    cout << endl;
}


int main()
{
    int N, R;
    vector<int> X;
    vector<int> book;

    input_data(&N, &R, X, book);
    //output_data(&N, &R, X, book);
    solve(&N, &R, X, book);

    return 0;
}
