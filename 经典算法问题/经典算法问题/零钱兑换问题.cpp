//有 1、7、10 这 3 种面值的纸币，每种纸币的数量不限，要求计算拼凑总面值 15 最少需要多少张纸币。
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    vector<int> dp(amount+1, INT_MAX-1);
    dp[0] = 0;   //动态规划基础情况
    for(int i = 0; i <= amount; i++){
        for(int coin : coins){
            if(coin <= i){
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
    }
    return dp[amount]==INT_MAX-1 ? -1 : dp[amount];
}

int main()
{
    vector<int> coins = {1, 7, 10};
    int amount = 15;  //总面值15
    int times = coinChange(coins, amount);
    cout<<"总面值"<<amount<<"元最少需要"<<times<<"张纸币"<<endl;
    return 0;
}