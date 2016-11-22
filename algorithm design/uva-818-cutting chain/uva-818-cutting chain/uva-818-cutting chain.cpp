// uva-818-cutting chain.cpp : �������̨Ӧ�ó������ڵ㡣
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
const int N = 20;
const int INF = 0x3f3f3f3f;
int n,cn,g[N][N],vis[N];
void init()
{
	int a,b;
	memset(g,0,sizeof(g));
	while(scanf("%d%d",&a,&b)!=EOF&&a!=-1&&b!=-1)
		g[b-1][a-1]=g[a-1][b-1]=1;
}
bool two(int s)//�ж�Ϊ0��λ�Ƿ��ж���2����֧
{
	for(int i = 0;i<n;i++)
	{
		if(s&(1<<i)) continue;
		int num = 0;
		for(int j = 0;j<n;j++)
		{
			if(s&(1<<j)) continue;
			if(g[i][j]) num++;
		}
		if(num>2) return true;
	}
	return false;
}
bool dfs(int s, int now, int fa)
{
	vis[now]=1;
	for(int i = 0;i<n;i++)
	{
		if(!g[now][i]||(s&(1<<i))||i==fa) continue;
		if(vis[i]) return true;//�ж��Ƿ��л�
		if(dfs(s,i,now)) return true;
	}
	return false;
}
bool circle(int s)//�Ƿ��л�
{
	for(int i = 0;i<n;i++)
	{
		if(vis[i]||(s&(1<<i))) continue;
		cn++;//��¼��֧�ĸ���
		if(dfs(s,i,-1)) return true;//��ǰ��֧�л�
	}
	return false;
}
int cal(int s)
{
	return s==0?0:cal(s/2)+(s&1);//����s��1�ĸ���
}
int solve()
{
	int ans = INF;
	int s = 1<<n;
	for(int i = 0;i<s;i++)
	{
		cn=0;
		memset(vis,0,sizeof(vis));
		if(two(i)||circle(i)) continue;//�л������ж���2����֧�ĵ�
		if(cal(i)>=cn-1)
			ans=min(cal(i),ans);//����i��1������Сֵ
	}
	return ans;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int kase = 0;
	while(scanf("%d",&n)!=EOF&&n)
	{
		init();
		printf("Set %d: Minimum links to open is %d\n",++kase,solve());
	}
}

