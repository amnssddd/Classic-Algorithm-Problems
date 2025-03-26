#include <iostream>
using namespace std;

//Բ������ ��ʼ�� Ŀ���� ������
void hanoi(int  num, char sou, char tar, char aux)
{
	if (num == 1) {
		cout << sou << "->" << tar << endl;
	}
	else {
		hanoi(num - 1, sou, aux, tar);         //������n-1��Բ�̴ӳ�ʼ���ƶ���������������Ŀ������
		cout << sou << "->" << tar << endl;    //������´�Բ�̴ӳ�ʼ���ƶ���Ŀ����
		hanoi(num - 1, aux, tar, sou);         //������n-1��Բ�̴Ӹ������ƶ���Ŀ������������ʼ����
	}
}

int main()
{
	//���ƶ� 3 ��Բ��Ϊ������ʼ����Ŀ�������������ֱ��� A��B��C ��ʾ
	hanoi(3, 'A', 'B', 'C');
	return 0;
}