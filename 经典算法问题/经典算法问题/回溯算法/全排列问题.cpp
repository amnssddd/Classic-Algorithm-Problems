//罗列指定集合中全部元素所有可能的排列情况
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArr(const vector<int>& res)
{
    for(int num : res){
        cout << num << " ";
    }
    cout<<"  ";
}

void permute(const vector<int>& arr, vector<int>& res, vector<bool>& used)
{
    if(arr.size() == res.size()){  //如果res数组已满足要求，则打印该结果并返回
        printArr(res);
        return;  //结束递归条件
    }
    //查找所有可能的值
    for(int i = 0; i < arr.size(); i++){
        //如果该元素已使用或该元素与前一个元素相等且前一个元素未使用，则跳过
        if(used[i] || (i>0 && arr[i]==arr[i-1] && !used[i-1])){
            continue;
        }
        //选择当前元素
        used[i] = true;
        res.push_back(arr[i]);
        //递归
        permute(arr, res, used);
        //回溯并初始化使用
        used[i] = false;
        res.pop_back();
    }
}

int main()
{
    vector<int> arr = {1, 2, 1};
    //排序方便处理相同元素
    sort(arr.begin(), arr.end());
    //创建辅助数组
    vector<int> res;  //初始化为空，通过push_back动态填充
    vector<bool> used(arr.size(), false);
    //调用全排列函数
    permute(arr, res, used);
}