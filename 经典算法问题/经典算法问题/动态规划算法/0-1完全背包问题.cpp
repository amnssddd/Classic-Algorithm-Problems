/*
虚拟一个场景，商店中拥有 5 种商品，它们各自的重量和收益分别是：
- 商品 1：重量 1 斤，收益 1 元；
- 商品 2：重量 2 斤，收益 6 元；
- 商品 3：重量 5 斤，收益 18 元；
- 商品 4：重量 6 斤，收益 22 元；
- 商品 5：重量 7 斤，收益 28 元。
假设背包的最大承重是 11 斤，各种商品的数量是**唯一/无限**的，如何选择才能实现背包的收益最大呢？
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
	vector<int> dp(capacity + 1, 0);   //承重不同的背包未装入商品时收益均为0
	for (const auto& item : items) {
        for (int j = capacity; j >= item.weight; j--) { // 逆序遍历
            dp[j] = max(dp[j], dp[j - item.weight] + item.value);  //状态转移方程
        }
    }
	return dp[capacity];
}

int knapsackCompleted(vector<Item>& items, int capacity)
{
	vector<int> dp(capacity + 1, 0);    //承重不同的背包未装入商品时收益均为0
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
    //0-1背包问题
	int capacity1 = 11;
    int maxValue1 = knapsack01(items, capacity1);
    cout << "0-1背包问题：在背包承重" << capacity1 << "斤的情况下最大收益为 " << maxValue1 << " 元" << endl;
    //完全背包问题
    int capacity2 = 15;
    int maxValue2 = knapsackCompleted(items, capacity2);
    cout << "完全背包问题：在背包承重" << capacity2 << "斤的情况下最大收益为 " << maxValue2 << " 元" << endl;
	return 0;
}
/*
0-1背包问题：在背包承重11斤的情况下最大收益为 40 元
完全背包问题：在背包承重11斤的情况下最大收益为 57 元
*/