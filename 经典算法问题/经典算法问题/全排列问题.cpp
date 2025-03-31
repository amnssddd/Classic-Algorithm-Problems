//����ָ��������ȫ��Ԫ�����п��ܵ��������
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
    if(arr.size() == res.size()){  //���res����������Ҫ�����ӡ�ý��������
        printArr(res);
        return;  //�����ݹ�����
    }
    //�������п��ܵ�ֵ
    for(int i = 0; i < arr.size(); i++){
        //�����Ԫ����ʹ�û��Ԫ����ǰһ��Ԫ�������ǰһ��Ԫ��δʹ�ã�������
        if(used[i] || (i>0 && arr[i]==arr[i-1] && !used[i-1])){
            continue;
        }
        //ѡ��ǰԪ��
        used[i] = true;
        res.push_back(arr[i]);
        //�ݹ�
        permute(arr, res, used);
        //���ݲ���ʼ��ʹ��
        used[i] = false;
        res.pop_back();
    }
}

int main()
{
    vector<int> arr = {1, 2, 1};
    //���򷽱㴦����ͬԪ��
    sort(arr.begin(), arr.end());
    //������������
    vector<int> res;  //��ʼ��Ϊ�գ�ͨ��push_back��̬���
    vector<bool> used(arr.size(), false);
    //����ȫ���к���
    permute(arr, res, used);
}