/*
假设商店中有 3 种商品，它们各自的重量和收益是：
商品 1：重量 10 斤，收益 60 元；
商品 2：重量 20 斤，收益 100 元；
商品 3：重量 30 斤，收益 120 元。

对于每件商品，顾客可以购买商品的一部分（可再分）。一个小偷想到商店行窃，他的背包最多只能装 50 斤的商品，如何选择才能获得最大的收益呢？
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//构造商品类
struct Item{
    int value;          //商品价值
    int weight;         //商品重量
    double valuePerWeight; //商品单位价值

    Item(int v,int w) : value(v), weight(w){
        valuePerWeight = (double)value/weight;
    }
};

//按单位价值降序排序
bool compareItems(const Item& a,const Item& b){
    return a.valuePerWeight > b.valuePerWeight;
}

//贪心算法解决部分背包问题
double fractionalKnapsack(int capacity,vector<Item>& items)
{
    //将商品按单位价值降序排序（符合贪心算法解）
    sort(items.begin(), items.end(), compareItems);
    double totalValue = 0.0;
    int remainCapacity = capacity;  //剩余背包容量（初始为满）

    //遍历排序后的商品
    for(const auto& item : items){
        if(remainCapacity <= 0){
            break;   //当包满后退出遍历
        }
        int takenWeight = min(item.weight, remainCapacity);
        totalValue += takenWeight * item.valuePerWeight;
        remainCapacity -= takenWeight;
    }
    return totalValue;
}

int main()
{
    vector<Item> items={  //价值，重量
        Item(60, 10),
        Item(100, 20),
        Item(120, 30)
    };
    int capacity = 50;  //最大容量
    double maxValue = fractionalKnapsack(capacity, items);
    cout<<"最大收益为 "<<maxValue<<" 元"<<endl;
    return 0;
}