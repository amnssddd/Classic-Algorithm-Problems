//�Ӹ����� N �������ҳ����� K �������������
#include <iostream>
#include <vector>
using namespace std;

const int K = 2;

void combintationUtil(const vector<int>& arr, vector<int>& data, int start, int index, int k)
{
    //�ҵ�һ����������Ϻ����������
    if(index == k){
        for(int j=0; j<k; j++){
            cout << data[j] << " ";
        }
        cout<<"  ";
        return;
    }
    //�ݹ����п������ɵ����
    for(int i=start; i<=arr.size()-(k-index); i++){
        data[index] = arr[i];
        combintationUtil(arr, data, i+1, index+1, k);
    }
}

//��ʼ��Ϲ���
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