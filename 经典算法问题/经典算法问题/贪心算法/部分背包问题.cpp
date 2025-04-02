/*
�����̵����� 3 ����Ʒ�����Ǹ��Ե������������ǣ�
��Ʒ 1������ 10 ����� 60 Ԫ��
��Ʒ 2������ 20 ����� 100 Ԫ��
��Ʒ 3������ 30 ����� 120 Ԫ��

����ÿ����Ʒ���˿Ϳ��Թ�����Ʒ��һ���֣����ٷ֣���һ��С͵�뵽�̵����ԣ����ı������ֻ��װ 50 �����Ʒ�����ѡ����ܻ�����������أ�
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//������Ʒ��
struct Item{
    int value;          //��Ʒ��ֵ
    int weight;         //��Ʒ����
    double valuePerWeight; //��Ʒ��λ��ֵ

    Item(int v,int w) : value(v), weight(w){
        valuePerWeight = (double)value/weight;
    }
};

//����λ��ֵ��������
bool compareItems(const Item& a,const Item& b){
    return a.valuePerWeight > b.valuePerWeight;
}

//̰���㷨������ֱ�������
double fractionalKnapsack(int capacity,vector<Item>& items)
{
    //����Ʒ����λ��ֵ�������򣨷���̰���㷨�⣩
    sort(items.begin(), items.end(), compareItems);
    double totalValue = 0.0;
    int remainCapacity = capacity;  //ʣ�౳����������ʼΪ����

    //������������Ʒ
    for(const auto& item : items){
        if(remainCapacity <= 0){
            break;   //���������˳�����
        }
        int takenWeight = min(item.weight, remainCapacity);
        totalValue += takenWeight * item.valuePerWeight;
        remainCapacity -= takenWeight;
    }
    return totalValue;
}

int main()
{
    vector<Item> items={  //��ֵ������
        Item(60, 10),
        Item(100, 20),
        Item(120, 30)
    };
    int capacity = 50;  //�������
    double maxValue = fractionalKnapsack(capacity, items);
    cout<<"�������Ϊ "<<maxValue<<" Ԫ"<<endl;
    return 0;
}