/*
假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，
都有一个尺寸 s[j]。如果 s[j]>=g[i]，我们可以将这个饼干j分配给孩子 i，这个孩子会得到满足。
你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//设孩子胃口数组g[]和饼干尺寸数组s[]
int findContentChildren(vector<int>& g, vector<int>& s)
{
    //对孩子胃口和饼干尺寸进行升序排序
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    int child = 0;  //满足的孩子数量
    int cookie = 0; //当前尝试的饼干索引

    while(child<g.size() && cookie<s.size()){
        if(s[cookie]>=g[child]){
            child++;
        }
        cookie++;
    }
    return child;
}

int main()
{
    vector<int> g = {3,1,2,4};
    vector<int> s = {1,2,2,3};
    int result = findContentChildren(g,s);
    cout<<"最多能满足的孩子数量："<<result<<endl;
}