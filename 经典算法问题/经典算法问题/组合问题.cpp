//从给定的 N 个数中找出任意 K 个数的所有组合
#include <iostream>
#include <vector>
using namespace std;

const int K = 2;

void combintationUtil(const vector<int>& arr, vector<int>& data, int start, int index, int k)
{
    //找到一个完整的组合后输出并返回
    if(index == k){
        for(int j=0; j<k; j++){
            cout << data[j] << " ";
        }
        cout<<"  ";
        return;
    }
    //递归所有可能生成的组合
    for(int i=start; i<=arr.size()-(k-index); i++){
        data[index] = arr[i];
        combintationUtil(arr, data, i+1, index+1, k);
    }
}

//开始组合过程
void printCombintation(const vector<int>& arr, int k)
{
    vector<int> data(k);
    combintationUtil(arr, data, 0, 0, k);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    printCombintation(arr, K);
    return 0;
}