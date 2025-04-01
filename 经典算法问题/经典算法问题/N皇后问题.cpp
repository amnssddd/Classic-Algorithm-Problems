#include <iostream>
#include <cstdlib>  //用于绝对值abs
using namespace std;

const int N = 4;  //皇后数量为4
int q[N + 1];     //每个皇后位于的列数
int cnt = 0;      //有多少解法

//打印皇后位置
void print(int n)
{
    cnt++;
    cout << "第" << cnt << "种解法，具体如下：" << endl;
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

//判断k行j列处是否能安全放置皇后
bool isSafe(int k, int j)
{
    for(int i = 1; i < k; i++){
        //如果由其它皇后位于同一列，或者位于对角线上，则该位置无法使用
        if(j == q[i] || abs(i - k) == abs(q[i] - j)){
            return false;
        }
    }
    return true;
}

//在棋盘上放置皇后
void n_queens(int k, int n)
{
    if(k > n){       //递归出口。此时已有一解，打印该结果
        print(n);
    }
    else{
        //检查k行的每一列，找出安全位置并放置皇后
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
    cout << "共有 " << cnt << " 种不同的排列" << endl;
    return 0;
}