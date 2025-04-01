#include <iostream>
#include <cstdlib>  //���ھ���ֵabs
using namespace std;

const int N = 4;  //�ʺ�����Ϊ4
int q[N + 1];     //ÿ���ʺ�λ�ڵ�����
int cnt = 0;      //�ж��ٽⷨ

//��ӡ�ʺ�λ��
void print(int n)
{
    cnt++;
    cout << "��" << cnt << "�ֽⷨ���������£�" << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j == q[i]){
                cout << "Q ";
            }
            else{
                cout << "x ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

//�ж�k��j�д��Ƿ��ܰ�ȫ���ûʺ�
bool isSafe(int k, int j)
{
    for(int i = 1; i < k; i++){
        //����������ʺ�λ��ͬһ�У�����λ�ڶԽ����ϣ����λ���޷�ʹ��
        if(j == q[i] || abs(i - k) == abs(q[i] - j)){
            return false;
        }
    }
    return true;
}

//�������Ϸ��ûʺ�
void n_queens(int k, int n)
{
    if(k > n){       //�ݹ���ڡ���ʱ����һ�⣬��ӡ�ý��
        print(n);
    }
    else{
        //���k�е�ÿһ�У��ҳ���ȫλ�ò����ûʺ�
        for(int j = 1; j<= n; j++){
            if(isSafe(k, j)){
                q[k] = j;
                n_queens(k + 1, n);
            }
        }
    }
}

int main()
{
    n_queens(1, N);
    cout << "���� " << cnt << " �ֲ�ͬ������" << endl;
    return 0;
}