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