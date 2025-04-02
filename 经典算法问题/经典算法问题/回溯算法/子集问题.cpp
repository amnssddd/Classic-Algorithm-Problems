//�û����㷨�ҳ��������ϵ������Ӽ�
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��ӡ
void printSubset(const vector<int>& subset)
{
    cout << "( ";
    for(int num : subset){
        cout << num << " ";
    }
    cout<<")"<<endl;
}

//�����㷨���
void subsetBacktrack(const vector<int>& arr, vector<int>& subset, vector<bool>& used, int startIndex)
{
    //��ӡ�Ӽ���ȷ�������Ӽ���������ʼ�Ŀռ������ܱ���ӡ
    printSubset(subset);

    //�����ظ�Ԫ��
    for(int i=startIndex; i<arr.size(); i++){
        if(i>0 && arr[i] == arr[i-1] && used[i-1] == false){ //used[i-1]Ϊfalse��ʾarr[i-1]��ʱ����subset�У�������ظ�Ԫ����ʡȥ
            continue;
        }
        //ѡ��ǰԪ��
        subset.push_back(arr[i]);  //β�巨����subset��
        used[i] = true;  //��ʾarr[i]��subset��
        //�ݹ����
        subsetBacktrack(arr, subset, used, i+1);
        //���ݳ���
        used[i] = false;
        subset.pop_back();
    }
}

//ǰ�ò���
void findAllsubsets(vector<int>& arr)
{
    //���򷽱㴦���ظ�Ԫ��
    sort(arr.begin(), arr.end());
    //���帨������
    vector<int> subset;
    vector<bool> used(arr.size(), false);
    //��������һ����
    subsetBacktrack(arr, subset, used, 0);
}

int main()
{
    vector<int> arr = {1, 1, 2};
    cout << "�ü��ϵ������Ӽ�Ϊ��" << endl;
    findAllsubsets(arr);
    return 0;
}