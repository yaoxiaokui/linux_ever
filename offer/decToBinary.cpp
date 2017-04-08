/*************************************************************************
	> File Name: decToBinary.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 25 Aug 2016 07:55:39 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<int> decTobin(int n)
{
    vector<int> v;
    while(n != 0){
        v.push_back(n % 2);
        n = n / 2;
    }

    return v;
}

void print(vector<int> & v)
{
    for(int i = 0; i < v.size(); ++i){
        cout << v[i];
    }
    cout << endl;
}

int getDiffCount(vector<int> & m, vector<int> & n)
{
    int mSize = m.size();
    int nSize = n.size();

    //cout << "mSize = " << mSize << ", nSize = " << nSize << endl;
    if(mSize > nSize){
        for(int i = 0; i < mSize-nSize; ++i)
            n.push_back(0);
    }
    else if(mSize < nSize){
        for(int i = 0; i < nSize-mSize; ++i)
            m.push_back(0);
    }

    int count = 0;
    mSize = m.size();
    nSize = n.size();

    //cout << "2  mSize = " << mSize << ", nSize = " << nSize << endl;
    //print(m);
    //print(n);

    for(int i = 0; i < m.size(); ++i){
        if(m[i] != n[i])
            count++;
    }

    return count;
}

int main()
{
    int m, n;
    cout << "input the m: ";
    cin >> m;
    cout << "input the n: ";
    cin >> n;


    vector<int> binaryOfm = decTobin(m);
    vector<int> binaryOfn = decTobin(n);

    cout << "m: ";
    print(binaryOfm);

    cout << "n: ";
    print(binaryOfn);

    cout << "diff count = " << getDiffCount(binaryOfm, binaryOfn) << endl;

    return 0;
}
