//̰���㷨���������������
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
        //̰��ѡ�񣺾����Ǽ��뵱ǰԪ�ػ���ѡ��ӵ�ǰԪ�����¿�ʼ
        current_sum = max(arr[i],current_sum+arr[i]);
        max_sum = max(max_sum,current_sum);
    }
    return max_sum;
}

int main()
{
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    int res = maxAddArray(arr);
    cout<<"������к�Ϊ��"<<res<<endl;
    return 0;
}