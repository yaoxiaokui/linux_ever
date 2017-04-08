/*************************************************************************
	> File Name: 46oneToN.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon Jul 11 08:50:48 2016
 ************************************************************************/

#include<iostream>
using namespace std;

class SumOneToN{

private:
    static int N;
    static int sum;
public:
    SumOneToN(){
        N++;
        sum += N;
    }

    static int getSum(){
        return sum;
    }
};

int SumOneToN::N = 0;
int SumOneToN::sum = 0;


//求1+2+...+n的和
int sumOneToN(int n)
{
    SumOneToN * sumOneToN = new SumOneToN[n];

    delete []sumOneToN;
    sumOneToN = NULL;

    return SumOneToN::sum;
}

//主函数
int main()
{
    cout << "Input the value of n: ";
    int n;
    cin >> n;

    cout << "1+2+...+" << n << " = " << sumOneToN(n) << endl;

    return 0;
}
