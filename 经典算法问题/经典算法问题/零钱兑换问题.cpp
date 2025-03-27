//�� 1��7��10 �� 3 ����ֵ��ֽ�ң�ÿ��ֽ�ҵ��������ޣ�Ҫ�����ƴ������ֵ 15 ������Ҫ������ֽ�ҡ�
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    vector<int> dp(amount+1, INT_MAX-1);
    dp[0] = 0;   //��̬�滮�������
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
    int amount = 15;  //����ֵ15
    int times = coinChange(coins, amount);
    cout<<"����ֵ"<<amount<<"Ԫ������Ҫ"<<times<<"��ֽ��"<<endl;
    return 0;
}