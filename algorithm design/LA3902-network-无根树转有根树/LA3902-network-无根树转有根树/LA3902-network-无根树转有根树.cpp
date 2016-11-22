// LA3902-network-�޸���ת�и���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int maxn = 1010;
vector<int> gr[maxn], nodes[maxn];
int n,s,k,fa[maxn];
bool covered[maxn];
void dfs(int u, int f, int d)
{
	fa[u]=f;//u�ĸ��ڵ�Ϊf
	int nc = gr[u].size();//�ڽӵ����
	if(nc==1&&d>k) nodes[d].push_back(u);//һ���ڽӵ� ΪҶ�� ���븸�ڵ�������k
	for(int i = 0;i<nc;i++)
	{
		int v = gr[u][i];
		if(v!=f) dfs(v,u,d+1);//�ݹ�u�ĺ��ӣ�����У�
	}
}
void dfs2(int u, int f, int d)
{
	covered[u]=true;
	int nc = gr[u].size();
	for(int i = 0;i<nc;i++)
	{
		int v = gr[u][i];
		if(v!=f&&d<k) dfs2(v,u,d+1);//��u�ܸ��ǵĽڵ����
	}
}
int solve()
{
	int ans = 0;
	memset(covered,0,sizeof(covered));
	for(int d = n-1;d>k;d--)//��������뿪ʼ
	{
		for(int i = 0;i<nodes[d].size();i++)
		{
			int u = nodes[d][i];
			if(covered[u])
				continue;
			int v = u;
			for(int j = 0;j<k;j++)
				v=fa[v];//������������k����Զ������
			dfs2(v,-1,0);//��v����Ϊ������  ����v��k�����ڵĵ㱻����
			ans++;
		}
	}
	return ans;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&s,&k);
		for(int i = 1;i<=n;i++)
		{
			gr[i].clear();
			nodes[i].clear();
		}
		for(int i = 0;i<n-1;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			gr[a].push_back(b);
			gr[b].push_back(a);
		}
		dfs(s,-1,0);
		printf("%d\n",solve());
	}
}

