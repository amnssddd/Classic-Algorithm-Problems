/*
��������һλ�ܰ��ļҳ�����Ҫ����ĺ�����һЩС���ɡ����ǣ�ÿ���������ֻ�ܸ�һ����ɡ�

��ÿ������ i������һ��θ��ֵ g[i]���������ú���������θ�ڵı��ɵ���С�ߴ磻����ÿ����� j��
����һ���ߴ� s[j]����� s[j]>=g[i]�����ǿ��Խ��������j��������� i��������ӻ�õ����㡣
���Ŀ���Ǿ���������Խ�������ĺ��ӣ��������������ֵ��
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//�躢��θ������g[]�ͱ��ɳߴ�����s[]
int findContentChildren(vector<int>& g, vector<int>& s)
{
    //�Ժ���θ�ںͱ��ɳߴ������������
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    int child = 0;  //����ĺ�������
    int cookie = 0; //��ǰ���Եı�������

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
    cout<<"���������ĺ���������"<<result<<endl;
}