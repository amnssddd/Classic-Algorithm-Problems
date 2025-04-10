//从给定的整数序列中找到连续的一串整数（至少包含 1 个整数），要求这串整数的和是所有整数串中最大的
#include <iostream>
#include <vector>
using namespace std;

int maxAddArray(vector<int>& arr)
{
    if(arr.empty()){
        return 0;
    }
    int current_sum = arr[0];
    int max_sum = arr[0];
    for(int i = 0; i < arr.size(); i++){
        //贪心选择：决定是加入当前元素还是选择从当前元素重新开始
        current_sum = max(arr[i],current_sum+arr[i]);
        max_sum = max(max_sum,current_sum);
    }
    return max_sum;
}

int main()
{
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    int res = maxAddArray(arr);
    cout<<"最大序列和为："<<res<<endl;
    return 0;
}