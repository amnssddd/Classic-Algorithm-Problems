//用回溯算法找出给定集合的所有子集
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//打印
void printSubset(const vector<int>& subset)
{
    cout << "( ";
    for(int num : subset){
        cout << num << " ";
    }
    cout<<")"<<endl;
}

//回溯算法求解
void subsetBacktrack(const vector<int>& arr, vector<int>& subset, vector<bool>& used, int startIndex)
{
    //打印子集，确保所有子集（包括初始的空集）都能被打印
    printSubset(subset);

    //处理重复元素
    for(int i=startIndex; i<arr.size(); i++){
        if(i>0 && arr[i] == arr[i-1] && used[i-1] == false){ //used[i-1]为false表示arr[i-1]此时不在subset中，因此是重复元素需省去
            continue;
        }
        //选择当前元素
        subset.push_back(arr[i]);  //尾插法插入subset中
        used[i] = true;  //表示arr[i]在subset中
        //递归调用
        subsetBacktrack(arr, subset, used, i+1);
        //回溯撤销
        used[i] = false;
        subset.pop_back();
    }
}

//前置操作
void findAllsubsets(vector<int>& arr)
{
    //排序方便处理重复元素
    sort(arr.begin(), arr.end());
    //定义辅助数组
    vector<int> subset;
    vector<bool> used(arr.size(), false);
    //“迈出第一步”
    subsetBacktrack(arr, subset, used, 0);
}

int main()
{
    vector<int> arr = {1, 1, 2};
    cout << "该集合的所有子集为：" << endl;
    findAllsubsets(arr);
    return 0;
}