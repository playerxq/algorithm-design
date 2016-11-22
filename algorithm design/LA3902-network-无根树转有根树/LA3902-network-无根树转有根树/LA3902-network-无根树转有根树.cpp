// LA3902-network-无根树转有根树.cpp : 定义控制台应用程序的入口点。
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
	fa[u]=f;//u的父节点为f
	int nc = gr[u].size();//邻接点个数
	if(nc==1&&d>k) nodes[d].push_back(u);//一个邻接点 为叶子 且离父节点距离大于k
	for(int i = 0;i<nc;i++)
	{
		int v = gr[u][i];
		if(v!=f) dfs(v,u,d+1);//递归u的孩子（如果有）
	}
}
void dfs2(int u, int f, int d)
{
	covered[u]=true;
	int nc = gr[u].size();
	for(int i = 0;i<nc;i++)
	{
		int v = gr[u][i];
		if(v!=f&&d<k) dfs2(v,u,d+1);//对u能覆盖的节点遍历
	}
}
int solve()
{
	int ans = 0;
	memset(covered,0,sizeof(covered));
	for(int d = n-1;d>k;d--)//从最深距离开始
	{
		for(int i = 0;i<nodes[d].size();i++)
		{
			int u = nodes[d][i];
			if(covered[u])
				continue;
			int v = u;
			for(int j = 0;j<k;j++)
				v=fa[v];//向上搜索距离k的最远的祖先
			dfs2(v,-1,0);//将v设置为服务器  所有v的k距离内的点被覆盖
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

