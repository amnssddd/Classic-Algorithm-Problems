/*
����һ���������̵���ӵ�� 5 ����Ʒ�����Ǹ��Ե�����������ֱ��ǣ�
- ��Ʒ 1������ 1 ����� 1 Ԫ��
- ��Ʒ 2������ 2 ����� 6 Ԫ��
- ��Ʒ 3������ 5 ����� 18 Ԫ��
- ��Ʒ 4������ 6 ����� 22 Ԫ��
- ��Ʒ 5������ 7 ����� 28 Ԫ��
���豳������������ 11 �������Ʒ��������**Ψһ/����**�ģ����ѡ�����ʵ�ֱ�������������أ�
*/
#include <iostream>
#include <vector>
using namespace std;

struct Item {
	int weight;
	int value;
	Item(int w, int v) : weight(w), value(v) {}
};

int knapsack01(vector<Item>& items, int capacity)
{
	vector<int> dp(capacity + 1, 0);   //���ز�ͬ�ı���δװ����Ʒʱ�����Ϊ0
	for (const auto& item : items) {
        for (int j = capacity; j >= item.weight; j--) { // �������
            dp[j] = max(dp[j], dp[j - item.weight] + item.value);  //״̬ת�Ʒ���
        }
    }
	return dp[capacity];
}

int knapsackCompleted(vector<Item>& items, int capacity)
{
	vector<int> dp(capacity + 1, 0);    //���ز�ͬ�ı���δװ����Ʒʱ�����Ϊ0
	for (int i = 0;i <= capacity;i++) {
		for (const auto& item : items) {
			if (i >= item.weight) {
				dp[i] = max(dp[i], dp[i - item.weight] + item.value);
			}
		}
	}
	return dp[capacity];
}

int main()
{
	vector<Item> items = {
		Item(1, 1),
		Item(2, 6),
		Item(5, 18),
		Item(6, 22),
		Item(7, 28)
	};
    //0-1��������
	int capacity1 = 11;
    int maxValue1 = knapsack01(items, capacity1);
    cout << "0-1�������⣺�ڱ�������" << capacity1 << "���������������Ϊ " << maxValue1 << " Ԫ" << endl;
    //��ȫ��������
    int capacity2 = 15;
    int maxValue2 = knapsackCompleted(items, capacity2);
    cout << "��ȫ�������⣺�ڱ�������" << capacity2 << "���������������Ϊ " << maxValue2 << " Ԫ" << endl;
	return 0;
}
/*
0-1�������⣺�ڱ�������11���������������Ϊ 40 Ԫ
��ȫ�������⣺�ڱ�������11���������������Ϊ 57 Ԫ
*/