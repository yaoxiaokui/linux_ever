/*************************************************************************
	> File Name: 24sequenceIsTree.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Jun 2016 10:09:16 AM CST
 ************************************************************************/

#include <iostream>

using namespace std;


bool VerifySequenceOfBST(int *arr, int length)
{
    if(arr == NULL || length <= 0)
        return false;

    int lastElement = arr[length-1];

    //判断左子树结点
    int i = 0;
    for(i = 0; i < length-1; ++i){
        if(arr[i] > lastElement)
            break;
    }

    //判断右子树结点
    int j = i;
    for(; j < length-1; ++j){
        if(arr[j] < lastElement)
            return false;
    }

    //递归查看左子树
    bool left;
    if(i > 0)
        left = VerifySequenceOfBST(arr, i);

    //递归查看右子树
    bool right;
    if(i < length-1)
        right = VerifySequenceOfBST(arr+i, length-i-1);

    return left && right;
}


int main()
{
    int arr[100];
    cout << "输入序列的长度: ";
    int length = 0;
    cin >> length;

    cout << "输入要判断的序列: ";
    for(int i = 0; i < length; ++i){
        cin >> arr[i];
    }

    if(VerifySequenceOfBST(arr, length)){
        cout << "序列是BST的后序遍历序列" << endl;
    }
    else{
        cout << "序列不是BST的后序遍历序列" << endl;
    }
    

    return 0;
}
